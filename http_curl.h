
#pragma once
#include <string>
namespace k {
using std::string;
class HttpClient {
 public:	
 virtual string Get(string url) = 0;
 virtual string post(string url,string data) = 0;
};
class Curl : public HttpClient {
 public:
          Curl();
         ~Curl();
  virtual string Get(string url);
  virtual string post(string url,string data){} ;
  static size_t write_data_cb(void * buffer,size_t size,size_t nmemb,void *userp);
 private:
  string result;
};
} //namespace end

