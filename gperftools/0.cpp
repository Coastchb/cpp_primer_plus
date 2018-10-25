/**
 * Created by coast on 2018/10/22
 */

#include <gperftools/profiler.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void f(int n )
{
  int i;
  for (i=0; i<n*n; ++i)
  {
    char *p = (char*)malloc(1024*1024*120);
    free(p);
  }
}

int main(int argc, char *argv[])
{
  if(argc != 2){
    cout << "Usage: 0 num" << endl;
    exit(1);
  }

  cout << argv[0] << endl;
  cout << argv[1] << endl;
  int num = atoi(argv[1]);
  cout << num << endl;
  ProfilerStart("test.prof");//开启性能分析
  f(num);
  ProfilerStop();//停止性能分析
  return 0;
}


// install gperftool and
// link $gperftool_dir/src/gperftool/ to /usr/local/include and
// link $gperftool_dir/.libs/libprofiler.a and libtcmalloc.a to /usr/local/lib and
// link $gperftool_dir/.libs/libprofiler.so* and libtcmalloc.so* to /usr/lib and
// link $gperftool_dir/src/pprof to /usr/bin

// compile:
// g++ -o 0 0.cpp -ltcmalloc -lprofiler

// run:
// ./0 1024
// and then
// pprof --text ./0 test.prof >test.txt
// or
// pprof --pdf ./0 test.prof >test.pdf
