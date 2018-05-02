/*
此文件为 正则匹配文件
*/

#pragma once

#define URLB "(http.*)://(([a-z0-9A-Z]*)\\.*([a-z0-9A-Z]+)\\.+([a-z0-9A-Z]+)\\.*([a-z0-9A-Z]*))(/.*)*"

#define NEW_PAGE "<a href=\"(http.?://[a-z0-9A-Z/\\.]*[a-z0-9A-Z/\\.]*.html)"
             //    http*  ://( **.)**. **(.**)

#define DOWNLOAD "src=\"(http.?://([a-z0-9A-Z\\.]*)\\.com[a-z0-9A-Z-/\\.]*jpg)"



//旅图网
#define wwwimgtripcom "src=\"(http.?://([a-z0-9A-Z\\.]*)\\.com[a-z0-9A-Z-/\\.]*jpg!small)"
