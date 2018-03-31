
#include <iostream>
#include <regex>
#include "parse.h"
#include "pthread_pool.h"
#include "Regex.h"
#include <unistd.h>

namespace k {
using namespace std;
extern Pthread_pool pool;
Parse * parse =new Parse;
UTABLE Parse::save_table;


//可能需要经常改动
void Parse::parse(string * data,string *url) {
/* mode for test or release
 If  mode are "test" then reading dest url from stdin and parse the page  only once
 if mode are "release" then the program will be running forever
*/
if(!check(*url))
  return;
string conf_save_path = config->GetValue("download_file_path");
static int count =0;
int  Mode =0;  
  Mode=0;
//cout<<*data<<endl;
//  for download
     string file_type = ".jpg";
     regex resource(DOWNLOAD);
     sregex_iterator it1(data->begin(),data->end(),resource);
     sregex_iterator end1;
    for( ;it1 != end1;it1++)
     {
     string number = to_string(count++);
     string path ="./download/"+number+file_type;
        if(Mode){
        cout<<it1->str(1)<<endl;
        }else{
        string s =it1->str(1);
        if(check(s))
           pool.Add_Work(new Download(s,path),nullptr);
        }
     }

// for page
     regex address(NEW_PAGE);
     sregex_iterator it(data->begin(),data->end(),address);
     sregex_iterator end;
    for( ;it != end;it++)
     {
        if(Mode){
        cout<<it->str(1)<<endl;
        }else{
        string s =it->str(1);
        pool.Add_Work(new Page(s),nullptr);
        sleep(2);
        }
     }
}

int Parse::check(string item) {
    UTABLE::iterator p = save_table.find(item);
    if(p != save_table.end())
      return -1;                           //exiset
    save_table.insert(item);
return 1;
}

} //end namespace

