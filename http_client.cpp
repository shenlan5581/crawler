#include <stdio.h>
#include <string.h>
#include "http_client.h"
#include <unistd.h>
#include <iostream>
#include <regex>
#include "config.h"
#include "log.h"
#include "http_curl.h"
#include "Regex.h"
#include "pthread_pool.h"
#include  <fstream>
#include <curl/curl.h> 

namespace k {
using namespace std;
//class Page 
int Page::handler() {
    Curl get;
    string data = get.Get(dest_url);   
    if(data.empty())
      return -1;
    parse->parse(&data,&dest_url);   
return 1;
}

//class download
int Download::handler() {
    save(dest_url,file_name);
return 0;
}
// 图片下载
int Download::save(const string& image_url, const string& save_address) {
    cout<<save_address<<endl;
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    FILE* fp = fopen(save_address.c_str(),"a");
    if(fp == NULL) {
       log_error("Open save file failed");
       return -1;
    }
    res = curl_easy_setopt(curl, CURLOPT_URL, image_url.c_str());
    if(res != CURLE_OK) {
        curl_easy_cleanup(curl);
        log_error("Get resource failed");
        return -1;
    }
    res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    res = curl_easy_perform(curl);
    fclose(fp);
    curl_easy_cleanup(curl);
   return  1; 
}





} // namespce k

