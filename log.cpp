#include "log.h"
#include <iostream>
namespace k {
using namespace std;
Log log;
time_t tm;
int Log::begin(){
filefd = fopen(SAVEFILENAME,"a");
if(filefd == NULL) {
   filefd = stdout;
   cout<<"Log file open or create failed"<<endl;
 }
} 
char * Log::getdate(){
time(&tm);
return ctime(&tm);
}
Log::Log(){
 begin();
}
}

	
