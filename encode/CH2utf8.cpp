#include <iostream> 
#include <string> 
#include <locale> 
#include <codecvt> 
#include <fstream> 
#include <boost/lexical_cast.hpp>

int64_t BKDRHash(const std::string& str, const int seed) {
  int64_t hash = 0;
  for ( char s : str) {
    auto x = (s % 256) & 0xFF;
    std::cout << x << std::endl;
    std::cout << "str:" << str << ", s:" << s << ", int(s):" <<  (int)(s) << ",x:" << x << std::endl;
    hash = hash * seed + x;
    hash = hash & 0x7FFFFFFF;
  }
  return hash;
}

int PartitionVideoLen(const uint& video_len) {
  int part = 0;
  if (video_len < 5000) {
    part = 0;
  } else if (video_len >= 120000) {
    part = 9;
  } else {
    // 5s~120s均匀分桶
    part = static_cast<int>((video_len - 5000) * 2 / 23000);
  }

  return part;
}

int main(int argc, char *argv[]) 
{ 
   /*
   auto hash_value = BKDRHash("武威军警", 131);
   std::cout << "hash_value:" << hash_value << std::endl;
   
   auto x = ('\xe6' % 256) & 0xFF;
   std::cout << x << std::endl;

   std::cout << boost::lexical_cast<int>("123") << std::endl;

   std::cout << boost::lexical_cast<std::HexTo<uint32_t> >("0x2a") << std::endl;*/

   std::cout << PartitionVideoLen(13000) << std::endl;
   std::cout << PartitionVideoLen(39000) << std::endl;
   std::cout << PartitionVideoLen(62000) << std::endl;



}