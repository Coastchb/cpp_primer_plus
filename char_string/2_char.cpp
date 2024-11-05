/**
 * Created by coast on 2018/11/2
 */
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  string str = "NBA player-科比.";
  cout << str.size() << endl;
  cout << str.substr(11,3) << endl; // Chinese character is 3-bytes long
  cout << "'" << str[0] << "' is lower:" << static_cast<bool>(islower(str[0])) << endl;
  cout << "'" << str[4] << "' is lower:" << boolalpha << islower(str[4]) << endl;
  cout << "'" << str[11] << "' is uppper:" << boolalpha << isupper(str[11]) << endl;
  cout << "'" << str[11] << "' is lower:" << boolalpha << islower(str[11]) << endl;
  cout << "'" << str[10] << "' is uppper:" << boolalpha << isupper(str[10]) << endl;
  cout << "'" << str[10] << "' is lower:" << boolalpha << islower(str[10]) << endl;

  cout << "'" << str[0] << "' is in alphabet:" << static_cast<bool>(isalpha(str[0])) << endl;
  cout << "'" << str[11] << "' is in alphabet:" << static_cast<bool>(isalpha(str[11])) << endl;
  cout << "'" << str[10] << "' is in alphabet:" << static_cast<bool>(isalpha(str[10])) << endl;

}