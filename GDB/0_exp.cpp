#include <iostream>
using namespace std;

static char buf[256];
static char* str;

int main() {
	cout << "Please input your string:" << endl;
	cin >> str;
	cout << "Your string is: " << str << endl;
	return 0;
}
