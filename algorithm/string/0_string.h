/**
 * Created by coast on 2019/4/21
 */
#include <iostream>
using namespace std;

class String {
private:
    char* str_;
    size_t len_;

public:
    String();
    String(const String&);
    String(const char*);
    ~String() {
      cout << "calling deconstruction function now...\n";
      delete[] this->str_;
    };

    String& operator=(const String&);

    bool operator==(const String&) const;
    String operator+(const String&) const;
    String& operator+=(const String&);
    char& operator[](const int&) const;

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, const String&);

    size_t size() const;
    const char* c_str() const;

};