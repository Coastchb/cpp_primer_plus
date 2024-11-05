#include <iostream>
#include "stock00.h"

int main() {
  Stock s1 = Stock("NanoSmart", 20, 12.50);
  s1.show();
  Stock s2;
  s2.show();

  std::cout << "top one: ";
  s1.topval(s2).show();
  return 0;
}