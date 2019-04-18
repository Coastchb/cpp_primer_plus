/**
 * Created by coast on 2019/4/18
 */

#include "1_static.h"

//int A::b_ = 2;  // illegal: non-static data member defined out-of-line
string A::str_ = "string in class A";
const string A::str1_ = "str1";
//const string A::str2_ = "str2"; // illegal: non-static data member defined out-of-line