/*
处理器对象

职责 
目标对象放入任务队列中等待执行

子类对象 
1 资源下载
2 新页面整理

对象构建时 参数需求 1一个解析器 2目标url
*/
#pragma once

#include <string>
#include "parse.h"

namespace k {
using namespace std;

class Http_Handler {
public:
virtual int handler()=0;
};

// resource 
class Download :public Http_Handler{
public:
  Download(string url,string path):dest_url(url),
          file_name(path){};
  ~Download(){}
  virtual int handler();
private:
  string dest_url;              // dest_url
  string file_name;             // save file path
  int save(const string& image_url, const string& save_address);
};
// new page
class Page :public Http_Handler{
public: 
  Page(string url):dest_url(url){};
  ~Page(){};
  virtual int handler();
   
private:
  string  dest_url;     // dest_url
};










} //namespace
