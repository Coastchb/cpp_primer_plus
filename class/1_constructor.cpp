/**
 * Created by coast on 2019/5/14
 */

#include <iostream>
#include <string>
using namespace std;

 class A {
 public:
     A() {
       a = 1;
     }

     A(A& other) {
       a = other.get_a();
     }

     int get_a() {
       return a;
     }

 private:
     int a;
 };

 int main(int argc, char* argv[]) {
   A obj_a;
   cout << obj_a.get_a() << endl;

   // A *obj_b = &A(obj_a); //  error: taking the address of a temporary object of type 'A'
   A obj_b(obj_a); // obj_a; // ok: A obj_b = obj_a;   error: A obj_b = A(obj_a);
   A* cur_obj = &obj_b;
   cout << cur_obj->get_a() << endl;

   return 0;
 }