#include <curl/curl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "http_curl.h"
#include "string.h"
namespace k {
using namespace std;
Curl::Curl() {
 curl_global_init(CURL_GLOBAL_DEFAULT);
}
Curl::~Curl(){
 curl_global_cleanup();
}
string Curl::Get(string url) {
cout<<"req:"<<url<<endl;
 CURL *curl;
 CURLcode res;
 curl = curl_easy_init();
 curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data_cb);  //set callback function
 curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
 curl_easy_setopt(curl,CURLOPT_WRITEDATA,this);              //set the fourth argument call back gets
 if(curl) {
   cout<<"perform"<<endl;
   res = curl_easy_perform(curl);
   curl_easy_cleanup(curl);
 }
cout<<result<<endl;
return result;
}
size_t Curl::write_data_cb(void * buffer,size_t size,size_t nmemb,void *userp) {
	Curl * cli = (Curl*)userp;
  string ret = (char *)buffer;
  cli->result+=ret;
  int wrlen = (int)size*(int)nmemb;
return wrlen;
}
} //namespace e



 /*
	size_t write_data_cb(void *buffer,size_t size,size_t nmemb,void *userp){
		printf("return: %s",buffer);

		printf("data:%s",(char*)(userp));
	}
	char data[]="argument";
	int main() {
		curl_global_init(CURL_GLOBAL_DEFAULT);
		CURL *curl;
		CURLcode res;
		curl = curl_easy_init();
		char * buffr;	
		size_t size;
		size_t nmemb;
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data_cb);  //set callback function
		curl_easy_setopt(curl,CURLOPT_WRITEDATA,&data);              //set the fourth argument call back gets
		if(curl) {
			curl_easy_setopt(curl,CURLOPT_URL,"127.0.0.1 /service_finder?operate=query&service_name=web");
			res = curl_easy_perform(curl);
			if(res != CURLE_OK) {
				cout<<"err"<<endl;
			}
			curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
	} */

//		 您可以通过设置另一个属性来控制回调函数在第四个参数中获得的数据：
//		 curl_easy_setopt（easyhandle，CURLOPT_WRITEDATA，＆internal_struct）;
	 
