/**
 * Created by coast on 2018/11/2
 */

#include <iostream>
#include <regex>
#include <string>
using namespace std;

static const char kSepMarkWord[] = "`";
static const char kSepMarkPhrase[] = "^";
static const char kSepMarkLP[] = ",";
static const char kSepMarkSP[] = "@";
static const char kSepMarkSilence[] = ".";

bool IsAbbreviation(const string& w) {
  // mark 1
  string pattern = "[A-Z"; // + "A";

  pattern.append(kSepMarkWord);  // the most efficient
  pattern.append(kSepMarkPhrase); // the least efficient
  pattern = pattern + kSepMarkLP ;    // it is also OK: pattern = kSepMarkLP + pattern;
  pattern += kSepMarkSP;        // the second most efficient
  pattern.append("\\");
  pattern.append(kSepMarkSilence);
  pattern.append("]+");
  cout << "The pattern is: " << pattern << endl;

  regex reg(pattern);
  return regex_match(w, reg);

}

int main(int argc, char* argv[]) {
  cout << IsAbbreviation("A^b.") << endl;
  cout << IsAbbreviation("A^B.") << endl;
  cout << IsAbbreviation("Captain`cool@") << endl;
  cout << IsAbbreviation("music`radio@") << endl;
  cout << IsAbbreviation("NBA player") << endl;
}