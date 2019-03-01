/**
 * Created by coast on 2019/2/22
 */
#include <iostream>
#include <string>
using namespace std;


int main(){
  char a[] = {'a', 'b', 'c'};
  int  b[] = {1,2,3};
  char * cptr = a;
  int * iptr = b;
  for (int i=0; i < 3; i++) {
    cout << cptr[i] << endl;
  }
  for (int i=0; i < 3; i++) {
    cout << *iptr << endl;
    iptr++;
  }

  string str = "abc哈哈额";
  //str = "汉字";
  cout << "len:" << str.size() << endl;
  cout << str[0] << endl;
  cout << str.substr(3,3) << endl;
  cout << str.substr(6,3) << endl;
  cout << str.substr(9,3) << endl;


  string ch;
  bool e = false;

  for(size_t i = 0; i < str.size(); ++i)
  {
    if (str[i] < 0)
    {
      if (e)
        cout << ' ';
      ch = "";
      ch += str[i];
      ch += str[i+1];
      ch += str[i+2];
      cout << ch << endl;
      i+=2;
      e = false;
    }
    else {
      cout << str[i];
      e = true;
    }
  }

}
