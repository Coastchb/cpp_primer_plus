/**
 * Created by coast on 2019/4/16
 */

#include <iostream>
using namespace std;

// 纯虚函数：必须在子类中重写（实现），父类中只提供函数声明；可以实现运行时多态
// 虚函数：  可以在子类中重写，父类中提供函数的默认实现；可以实现运行时多态
// 普通函数：可以在子类中有个相同的函数，而且名称相同并没有什么意义，因为不可以实现运行时多态 (函数隐藏）

class A
{
public:
    virtual void out1()=0;  ///由子类实现
    virtual ~A(){};
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
    virtual ~B(){};

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
};

int main()
{
  cout << "====== A * ======" << endl;
  A *ab=new B;
  ab->out1();
  ab->out2();
  ab->out3();

  cout << "====== B * ======" << endl;
  B *bb=new B;
  bb->out1();
  bb->out2();
  bb->out3();

  delete ab;
  delete bb;

  cout << "====== A & ======" << endl;
  B b;
  A& abb = b;
  abb.out1();
  abb.out2();
  abb.out3();

  return 0;
}