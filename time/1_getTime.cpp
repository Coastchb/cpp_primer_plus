#include <iostream>
#include <time.h>

void timestamp2date() {
  time_t rawtime = (time_t)1619118570;
  struct tm * timeinfo = localtime (&rawtime);
  std::cout << "timestampe to date:" << asctime(timeinfo);
  std::cout << timeinfo->tm_hour << std::endl;
}

void getCurTime() {
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime (&rawtime);
    std::cout << timeinfo->tm_hour << ":" << timeinfo->tm_min << std::endl;
    std::cout << rawtime << std::endl;
}

int main() {
    getCurTime();
    timestamp2date();
}
