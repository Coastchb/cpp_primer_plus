/**
 * Created by coast on 2019/4/16
 */

#include <iostream>
using namespace std;

// 纯虚函数：必须在子类中重写（实现），父类中只提供函数声明；可以实现运行时多态
// 虚函数：  可以在子类中重写，父类中提供函数的默认实现；可以实现运行时多态
// 普通函数：可以在子类中有个相同的函数，而且名称相同并没有什么意义，因为不可以实现运行时多态 (函数隐藏）
// 被声明为父类的指针或者引用实际指向子类对象，并且调用父类中的虚函数，才会有多态。
// 把父类析构函数设为虚函数。
// 不论什么情况下（构造函数虚实与否，等等），构造子类对象都会先调用父类构造函数然后调用子类构造函数。

class A
{
public:
    A() {
      cout << "A()\n";
    }
    virtual void out1()=0;  ///由子类实现
    virtual ~A(){ cout << "~A()\n";};
    virtual void out2() ///默认实现
    {
      cout<<"A(out2)"<<endl;
    }
    void out3() ///强制实现
    {
      cout<<"A(out3)"<<endl;
    }
};

class B:public A
{
public:

    B() {
      cout << "B()\n";
    }

    ~B(){
      cout << "~B()\n";
    };

    void out1() {
      cout << "B(out1)" << endl;
    }
    void out2()
    {
      cout<<"B(out2)"<<endl;
    }
    void out3()
    {
      cout<<"B(out3)"<<endl;
    }
    void out4()
    {
      cout <<"B(out4)"<<endl;
    }
};

int main()
{
  cout << "====== A * ======" << endl;
  A *ab=new B;
  ab->out1();
  ab->out2();
  ab->out3();
  //ab->out4();   // out4() 在父类中不存在，不能调用
  delete ab;

  cout << "====== A & ======" << endl;
  B b;
  A& abb = b;
  abb.out1();
  abb.out2();
  abb.out3();
  //abb.out4();   // out4() 在父类中不存在，不能调用

  cout << "====== B * ======" << endl;
  B *bb=new B;
  bb->out1();
  bb->out2();
  bb->out3();
  bb->out4();

  delete bb;


  return 0;
}