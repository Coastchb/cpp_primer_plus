//
// Created by 操海兵 on 04/06/2018.
//

#include <cstring>
#include "dma.h"
using std::cout;
using std::endl;

baseDMA::baseDMA(const char *l, int r) {
  int l_len = std::strlen(l);
  label = new char[l_len + 1];
  std::strcpy(label, l);
  rating = r;
}
baseDMA::baseDMA(const baseDMA& rs) {
  int l_len = std::strlen(rs.label);
  label = new char[l_len + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
}
baseDMA::~baseDMA() {
  delete [] label;
}
baseDMA& baseDMA::operator=(const baseDMA &rs) {
  if(this == &rs)
    return *this;
  delete [] label;
  int l_len = std::strlen(rs.label);
  label = new char[l_len + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const baseDMA& rs){
  out << "Label: " << rs.label << ";"
       << "rating: " << rs.rating << endl;
  return out;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l,r){
  int c_len = std::strlen(c);
  std::strcpy(color, c);
}
lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs) {
  std::strcpy(color, c);
}
std::ostream& operator<<(std::ostream& out, const lacksDMA& rs){
  //baseDMA::operator<<(out, rs);
  out << (const baseDMA& )rs;
  out << "color: " << rs.color << endl;
  return out;
}
hasDMA::hasDMA(const char *s, char *l, int r) : baseDMA(l, r) {
  int s_len = std::strlen(s);
  style = new char[s_len + 1];
  std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs){
  int s_len = std::strlen(s);
  style = new char[s_len + 1];
  std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &rs) : baseDMA(rs) {
  int s_len = std::strlen(rs.style);
  style = new char[s_len + 1];
  std::strcpy(style, rs.style);
}
hasDMA::~hasDMA() {
  delete [] style;
}
hasDMA& hasDMA::operator=(const hasDMA &rs) {
  if(this == &rs)
    return *this;
  // mark 4
  baseDMA::operator=(rs);
  delete [] style;
  int s_len = std::strlen(rs.style);
  style = new char[s_len + 1];
  std::strcpy(style, rs.style);
  return *this;
}
std::ostream& operator<<(std::ostream& out, const hasDMA& rs){
  //baseDMA::operator<<(out, rs);
  // mark 5
  out << (const baseDMA&)rs;
  out << "style: " << rs.style << endl;
  return out;
}
