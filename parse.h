/*
这里做文件的解析
职责 
解析网络地址 生成对象 放入队列
例如 如果解析出 的是网址
    则创建相page对象放入队列
    如果是要下载的资源
    则创建download对象

*/
#pragma once
#include <vector>
#include <string>
#include <set>

namespace k{ 
using namespace std;
// new type for save already
typedef set<string> UTABLE;
class Parse {
 public:
   virtual void parse(string * data,string *url);
 private:
   static UTABLE save_table;   // static obj 
   int     check(string item);
};

extern Parse *parse;
}
