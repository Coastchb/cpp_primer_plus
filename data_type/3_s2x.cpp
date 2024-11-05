// stoull example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoull

int main() {


  std::string str = "8246821 0xffff 020 -1";

  std::string::size_type sz = 0;   // alias of size_t

  while (!str.empty()) {
    unsigned long long ull = std::stoull (str,&sz,0);
    std::cout << str.substr(0,sz) << " interpreted as " << ull << '\n';
    str = str.substr(sz);
  }
  
  /*
  std::string str1 = " "; // could not be converted
  std::cout << "aa:" << str1 << std::endl;
  std::cout << std::stoull(str1) << std::endl;
  */

  std::string str2 = "1618850690000";
  long i = std::stol(str2);
  std::cout << i << std::endl;

  return 0;
}