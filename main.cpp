#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include "http_client.h"
#include <iostream>
#include <string>
#include <string.h>
#include <regex>
#include "http_curl.h"
#include "pthread_pool.h"
#include "config.h"
using namespace k;
using namespace std;

void r() {
    string url = "https://www.baidu.com.cn/uri444444et4t4"  ;  
    regex address("http.?://(([a-z0-9A-Z]*)\\.*([a-z0-9A-Z]+)\\.+([a-z0-9A-Z]+)\\.*([a-z0-9A-Z]*))(/.*)");
//                                                                                       
    sregex_iterator it(url.begin(),url.end(),address);
    sregex_iterator end;
    for( ;it != end;it++) {
     cout<<it->str(0)<<endl;
     cout<<it->str(1)<<endl;
     cout<<it->str(2)<<endl;
     cout<<it->str(3)<<endl;
     cout<<it->str(4)<<endl;
     cout<<it->str(5)<<endl;
     cout<<it->str(6)<<endl;
    }
}

namespace k {
Pthread_pool pool;
}
int main() {
using namespace k;
cout<<"[crawler start run time:"<<endl;
pool.Init();
  string index;
  cout<<"code in the first page:";
 cin>>index;
  pool.Add_Work(new Page(index),nullptr);
  sleep(100);
}
