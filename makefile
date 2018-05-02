ifeq ($(make_basedir), ) 
	make_basedir := 
endif

CXXFLAGS := -g  -std=c++11
INCLUDE := -I.
INCLUDE += -I$(make_basedir) lib
INCLUDE += -I$(make_basedir) include
INCLUDE += -I$(make_basedir) lib/mysql/include
INCLUDE += -I$(make_basedir) lib/pugixml
INCLUDE += -I$(make_basedir) lib/curl/include

LIBDIR := -L. 
LIBDIR += -L$(make_basedir) lib
LIBDIR += -L$(make_basedir) lib/mysql 
LIBDIR += -L/usr/lib64 
 
LIB := -lcurl  -lpthread

src :=main.cpp 
src +=http_client.cpp
src +=config.cpp
src +=log.cpp
src +=parse.cpp
src += ./lib/pugixml/pugixml.cpp
src +=http_curl.cpp
src +=pthread_pool.cpp

.cpp.o:
	g++ $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

obj =$(src:.cpp=.o)

run:all
	./main
all:$(obj)
	g++  -o main $(obj) $(CXXFLAGS) $(INCLUDE) $(LIBDIR) $(LIB)  -Wl,-rpath,./lib/mysql   -fPIC

clean:$(obj)
	rm -f *.o
	rm -f main
