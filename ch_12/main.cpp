#include <iostream>
#include "strngbad.h"
#include "string.h"

/*
 * mark 1:  重载函数，尽量使用友元函数，函数的形参为（对象，对象），
 *          这样，（基本类型，对象）、（对象，对象），（对象，基本类型）这三种
 *          方式作为参数，都可以调用函数（当然，要提供以基本类型为唯一非默认
 *          参数的构造函数，让第一种方式中，基本类型能自动转换为对象。
 *          如果重载函数是成员函数，那么只能以后两种为参数列表。
 * mark 2:  如果对象是const，那么只能调用const函数；否则，const和非const函数
 *          都可以调用。
 * mark 3:  非char指针或者数组，要是取指定元素及其地址都很常规，容易理解。
 *          char指针或者数组名，传递给cout，会自动输出从该地址开始到'\0'的字符串；
 *          如果想输出地址，使用static_cast<void *>()进行转换。
 * mark 4:  const函数可以修改static变量；
 *          static函数只能访问static变量。
 * mark 5:  不同于构造函数（对象第一次创建，创建前没有任何内存用于存储跟它有关的数据），
 *          赋值函数（重载的=运算符）是将一个对象里的数据复制给另一个对象。所以，赋值函数里，
 *          需要先对接受赋值的对象释放动态分配的内存（如果有的话）。
 * mark 6:  string s1 = s2会调用复制构造函数，这是在初始化；而s1=s2不会调用，它只是简单的赋值。
 * mark 7:  注意对比两个函数的返回类型。如果不是返回对象的引用，那么，返回时，将调用复制构造函数，
 *          构造一个临时对象，并返回。（返回引用时，引用所指的数据对象一定要在调用函数中存在，
 *          而不能是在被调用函数中定义的数据对象；如果要返回函数中的局部变量，那就只能返回变量，
 *          而不能是其指针或者引用）
 *          （其实两个函数，只需要后一个就可以）
 * mark 8:  注意一个非常隐蔽的点：一个对象赋值给另一个对象，是把前者的所有数据复制给后者。所以，
 *          如果对象的数据中有指针，那么指针直接复制，导致两个对象有指向共同地址的指针。这就导致
 *          两者中，第二次释放对象时，释放已经释放过的内存（那个共同指向的内存已经被释放）。
 *
 * ### 如果成员数据中有指针，应注意：
 * （1）所有构造函数中，new形式要相同，并和析构函数里的delete形式一致。(new和delete,new [] 和 delete [])
 * （2）提供复制构造函数。并在构造函数中实现深度复制，而不仅仅是指针传递。
 * （3）提供对象给对象的赋值函数，（或者可能的基本类型给对象的赋值函数），在函数里实现深度复制。
 * （4）char * str; str = "abc";本身没有问题，但是这不属于动态分配内存（使用new）。由于析构函数中使用了delete [] 来释放
 *      动态分配的内存，所以，在构造函数中，不能使用str="abc"这种初始化方法。
 *      （使用了new来动态分配内存，一定要记得使用delete来释放相应的内存。在delete的时候，一定要注意，对应的内存是否已经
 *        被释放（浅拷贝给了另一个指针，被这个指针释放），如果已经被释放，就会导致delete时发生错误。）
 */

using std::cout;
using std::endl;

void callme1(StringBad &);
void callme2(StringBad);
void bad_str();
int & fun(int arr[]);
void mess();
void about_str_add();
int main() {
  {
    string s1 = "abc";
    const string s2 = "Abc";

    // mark 1
    cout << (s1 > s2) << endl;
    cout << (s1 > "Bbc") << endl;
    cout << ("bbc" > s1) << endl << endl;
    //cout << ("bbc" > "Bbc") << endl << endl;

    cout << s1[1] << endl;
    s1[1] = 'B';
    cout << s1 << endl << endl;

    // mark 2
    cout << s2[1] << endl;
    //s2[1] = 'B';
    cout << s2 << endl << endl;

    cout << string::HowMany() << endl << endl;

    // mark 6
    string a = s2;
    cout << endl;
    // mark 8
    a = "aa";
    cout << endl;
    a = s1;
    a = a;

    // It is OK
    char * aa, *c;
    char * p = "ab";
    aa = p;
    c = p;
    cout << c << endl;
    cout << static_cast<void *>(aa) << endl << static_cast<void *>(p) << endl << static_cast<void *>(c) << endl;


  }
  cout << endl <<  "end of main" << endl;
  return 0;
}

void callme1(StringBad & rsb)
{
  cout << "String passed by reference:\n";
  cout << " \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
  cout << "String passed by value:\n";
  cout << " \"" << sb << "\"\n";
}
void badstr(){
  cout << "Starting a inner block.\n";
  StringBad headline1("Celery Stolks at midnight");
  StringBad headline2("Lettuce Prey");
  StringBad sports("Spinash Leaves Bowl for Dollars");
  cout << "headline1:"<< headline1 << endl;
  cout << "headline2:" << headline2 << endl;
  cout << "sports:" << sports << endl;
  callme1(headline1);
  cout << "headline1:" << headline1 << endl;
  callme2(headline2);
  cout << "headline2:" << headline2 << endl;
  cout << "Initialize one object to another:\n";
  StringBad sailor = sports;
  cout << "sailor:" << sailor << endl;
  cout << "Assign one object to another:\n";
  StringBad knot;
  knot = headline1;
  cout << "knot:" << knot << endl;
  cout << "Exiting the block.\n";
}
int & fun(int arr[]){
  arr[0] = 4;
  return arr[1];
}
void mess(){
  int a[] = {1 , 2};
  int b = fun(a);
  b = 3;
  for (int i = 0; i < 2; ++i)
    std::cout << a[i] << std::endl;

  std::cout << b << std::endl;
  std::cout << "add of a[1] :" << &a[1] << std::endl;
  std::cout << "add of b : " << &b << std::endl;
}
void about_str_add(){
  /*
  string str1 = "String one";
  string str2 = "String two";
 // std::cout << str1 << std::endl;
  char c = str1[1];
  std::cout << c << " at " << &c << std::endl;
  */

  int a [3] = {1,2,3};
  std::cout << a << std::endl;
  std::cout << (a + 1) << std::endl;
  std::cout << &a[1] << std::endl;
  std::cout << endl;

  char * s1 = "abcd";
  char * s2 = new char[5];
  std::strcpy(s2,s1);

  // mark 3
  //cout << "&s2:" << &s2 << endl; // address of the char point
  cout << "static_cast<void *>(s2):" << static_cast<void *>(s2) << endl;
  //cout << &(s2 + 1 ) << endl;
  //cout << "&s1:" << &s1 << endl;
  cout << "static_cast<void *>(s1):" << static_cast<void *>(s1) << endl;
  const char aa = s1[1];
  cout << "s1[1]:" << aa << endl;
  cout << s1[1] << " at : " << static_cast<void *> (s1 + 1 )<< endl;
  //cout << "typeof(&s1):" << sizeof(&s1) << endl;
  cout <<  endl;

  char s3[4] = {'a','b','c'};
  cout << s3 << " at " << static_cast<void *>(s3) << endl;
  cout << "static_cast<void *>(s3):" << static_cast<void *>(s3) << endl;
  //cout << &s3 + 1 << endl;
  //cout << &s3+1 << endl;
  cout << sizeof(s3) << endl;
}