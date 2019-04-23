/**
 * Created by coast on 2019/4/21
 */
#include "0_string.h"

String::String(){
  str_ = new char(97);
  len_ = 0;
}

String::String(const String & str) {
  cout << "calling copy construction function now...\n";

  size_t length = str.size();
  this->str_ = new char[1];
  this->len_ = length;
  for(int i = 0; i <= length; i++) {
    this->str_[i] = str.str_[i];
  }
}

String::String(const char* cp) {
  cout << "calling String(const char*) now...\n";
  size_t length = 0;
  this->str_ = new char[1];
  while(*cp != 0) {
    this->str_[length++] = *cp;
    cp++;
  }
  this->str_[length] = 0;
  this->len_ = length;

}

String& String::operator=(const String & str) {
  cout << "calling assign operation now...\n";
  delete this->str_;
  this->len_ = str.len_;
  this->str_ = new char[this->len_+1];
  for(size_t i = 0; i <= this->len_; i++)
    this->str_[i] = str.str_[i];
  return *this;
}
size_t String::size() const {
  return this->len_;
}

const char* String::c_str() const{
  return this->str_;
}

ostream& operator<<(ostream& os, const String& str) {
  os << str.str_;
  return os;
}

istream& operator>>(istream& is, const String& str) {
  is >> str.str_;
  return is;
}

bool String::operator==(const String& str) const {
  if(this->str_ == NULL && str.str_ == NULL)
    return true;
  if(this->str_ == NULL || str.str_ == NULL)
    return false;
  if(this->len_ != str.len_)
    return false;
  for(size_t i = 0; i < this->len_; i++)
    if(this->str_[i] != str.str_[i])
      return false;

  return true;
}

String String::operator+(const String& str) const {
  String ret;
  //ret.str_ = new char[this->len_+1];
  for(size_t i = 0; i < this->len_; i++)
    ret.str_[i] = this->str_[i];
  for(size_t i = 0; i < str.len_; i++)
    ret.str_[this->len_ + i] = str.str_[i];
  ret.len_ = this->len_ + str.len_;
  ret.str_[ret.len_] = 0;
  return ret;
}

String& String::operator+=(const String& str) {
  size_t len = this->len_ + str.len_;
  char* tmp = new char[len_ + 1];
  for(size_t i = 0; i < this->len_; i++)
    tmp[i] = this->str_[i];
  delete this->str_;
  for(size_t i = 0; i < str.len_; i++)
    tmp[this->len_ + i] = str.str_[i];
  tmp[len] = 0;
  this->str_ = tmp;
  return *this;
}

char& String::operator[](const int& i) const {
  return this->str_[i];
}

int main(int argc, char* argv[]) {
  String str0;
  cout << "after calling string():str0=\"" << str0 << "\";at:" << (void *)str0.c_str() << endl;

  const char* cp = "a string";
  String str1 = String(cp);
  cout << "after calling string(const char*):str1=\"" << str1 << "\";at:" << (void *)str1.c_str() << endl;

  String str2 = str1;
  cout << "after calling string(const String&):str2=\"" << str2 << "\";at:" << (void *)str2.c_str() << endl;

  String str3 = "A string";
  cout << "str3=\"" << str3 << "\";at:" << (void *)str3.c_str() << endl;

  str2 = str1;

  cout << "the third char in str2:" << str2[2] << "\t" << str2.operator[](2) << endl;

  cout << "str2:" << str2 << "\tstr1:" << str1 << "\tstr2==str1:" << (str2 == str1) << "\n";
  cout << "str2:" << str2 << "\tstr1:" << str1 << "\tstr2+=str1:\"" << (str2+=str1) << "\";at:" << (void *)str2.c_str() << endl;
  cout << "str3:" << str3 << "at:" << (void *)str3.c_str() << endl;
  cout << "str3:" << str3 << "\tstr3+str3:" << (str3+str3) << endl;
  cout << "str1:" << str1 << "\tstr2:" << str2 << "\tstr1+str2:" << (str1 + str2) << endl;

  return 0;
}