// vector assignment
#include <iostream>
#include <random>

int main ()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,1);
  std::bernoulli_distribution distribution1(0.5);

  
  for(int i = 0; i < 6; i++) {
      std::cout << distribution(generator) << std::endl;
  }
  
  std::cout << std::endl;
  
  for(int i = 0; i < 6; i++) {
      std::cout << distribution1(generator) << std::endl;
  }
  std::cout << std::endl;
  
  static std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0,10);
  for(int i = 0; i < 6; i++) {
      std::cout << dis(gen) << std::endl;
  }
  return 0;
}