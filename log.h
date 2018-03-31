/*
日志等级 4 全部
          3 nodebug
          2 no info
          1 no warn
只需要包含该头文件
使用：
   log_info("...");
日志文件为当前文件 LOG (有io缓冲）
*/
#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
using namespace std;
namespace k {
class Log {
public:
   Log();
   int begin();
 FILE* filefd;
 char * getdate();
 time_t tm;
};
extern Log log;
#define DATE   log.getdate()
#define SAVEFILENAME "./LOG"
#define FILENAME  log.filefd

#ifndef LOGLEVEL 
#define LOGLEVEL 4   //all
#endif

#if LOGLEVEL < 3    
#define NDEBUG 1
#endif

#ifdef NDEBUG    
#define log_debug(M,ARGS...) //no debug
#else 
#define log_debug(M,ARGS...) fprintf(FILENAME,"DEBUG " M " at %s (%s:%d) %s",##ARGS,__func__,__FILE__,__LINE__,DATE)
#endif 
#define log_info(M,ARGS...) fprintf(FILENAME,"INFO " M " at %s (%s:%d) %s",##ARGS,__func__,__FILE__,__LINE__,DATE)
#define log_warn(M,ARGS...) fprintf(FILENAME,"WARN " M " at %s (%s:%d) %s",##ARGS,__func__,__FILE__,__LINE__,DATE)
#define log_error(M,ARGS...) fprintf(FILENAME,"ERROR " M " at %s (%s:%d) %s",##ARGS,__func__,__FILE__,__LINE__,DATE)

#if LOGLEVEL < 4             // delete info
#undef  log_info
#define log_info(M,ARGS...)
#endif

#if LOGLEVEL < 2             //delete warn
#undef  log_warn
#define log_warn(M,ARGS...)
#endif

#if LOGLEVEL < 1             //delete all
#undef  log_err
#define log_err(M,ARGS...)
#endif
	
	
} 

#endif // LOG_H 



























