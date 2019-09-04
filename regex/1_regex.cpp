/**
 * Created by coast on 2018/11/21
 */
#include <regex>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
  string str = "XX^SIL-er+l=ing@1_1/A:X_X_X+X/B:4-X=1-m@1-4&1-6#6-1"; //"^Hello_2018";
  smatch result;
  regex pattern("\\w+\\^([A-Za-z]+-([A-Za-z]+)\\+[A-Za-z]+).*"); //+-[A-Za-z]+\\+[A-Za-z]+)");        //"(\\^\\w+)_(\\d{4})");

  if (regex_match(str, result, pattern))
  {
    cout << result[0] << endl;      //完整匹配结果，"XX^SIL-er+l=ing@1_1/A:X_X_X+X/B:4-X=1-m@1-4&1-6#6-1"
    cout << result[1] << endl;      //第一组匹配的数据，"SIL-er+l"
    cout << result[2] << endl;      //第二组匹配的数据，"er"
    cout<<"结果显示形式2"<<endl;
    cout<< result.str() << endl;    //完整匹配结果，"XX^SIL-er+l=ing@1_1/A:X_X_X+X/B:4-X=1-m@1-4&1-6#6-1"
    cout<< result.str(1) << endl;   //第一组匹配的数据，"SIL-er+l"
    cout << result.str(2) << endl;  //第二组匹配的数据，"er"
  }

//遍历结果
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << endl;
  }


  str = "XX-sil+C0y/A:XX_XX@XX$1#4/B:XX_XX@XX$XX#XX&XX/E:XX/V:XX_XX@XX$XX/M:0_0@XX$XX#XX&XX>20<0/P:XX_0@3$XX#XX&XX>XX<XX/K:XX_XX@XX$XX#XX&XX>XX<XX^XX/G:XX_XX@XX$XX#XX&XX/L:XX_XX@XX$XX#XX&XX>XX/N:XX_XX@XX$XX#XX&XX>XX";
  regex pattern1("\\w+-([a-zA-Z0]+)+.*>([0-9]+)<([0-9])/P.*"); //("\\w+-([a-zA-Z]+)+.*>([0-9]+)<([0-9])/P.*"); //".*>([0-9]+)<([0-9])/P.*");
  smatch ret;
  if(regex_match(str, ret, pattern1)) {
      cout << ret.str(1) << endl;
      cout << ret.str(2) << endl;
  }

  ifstream fis("test_data/full_lab.txt");
  const int NUM = 1024;
  char line[NUM];
  while(fis.getline(line, NUM)) {
      str = string(line);
      if (regex_match(str, ret, pattern1)) {
          cout << ret.str(1) << endl;
          cout << ret.str(2) << endl;
      }
  }

}

