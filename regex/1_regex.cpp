/**
 * Created by coast on 2018/11/21
 */
#include <regex>
#include <iostream>
using namespace std;
int main() {
  string str = "XX^SIL-er+l=ing@1_1/A:X_X_X+X/B:4-X=1-m@1-4&1-6#6-1"; //"^Hello_2018";
  smatch result;
  regex pattern("\\w+\\^([A-Za-z]+-([A-Za-z]+)\\+[A-Za-z]+).*"); //+-[A-Za-z]+\\+[A-Za-z]+)");        //"(\\^\\w+)_(\\d{4})");

  if (regex_match(str, result, pattern))
  {
    cout << result[0] << endl;      //完整匹配结果，Hello_2018
    cout << result[1] << endl;      //第一组匹配的数据，Hello
    cout << result[2] << endl;      //第二组匹配的数据，2018
    cout<<"结果显示形式2"<<endl;
    cout<< result.str() << endl;    //完整结果，Hello_2018
    cout<< result.str(1) << endl;   //第一组匹配的数据，Hello
    cout << result.str(2) << endl;  //第二组匹配的数据，2018
  }

//遍历结果
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << endl;
  }

}

