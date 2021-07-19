#include <iostream>
#include <map>
 
using namespace std;
 
int main()
{
    map<int, int> a = {{1, 12}, {2, 23}, {3, 34}, {4, 45}, {5, 56}, {6, 67}};
    
    auto iter = a.begin();
    while(iter != a.end()) {
        if (iter->second > 30) {
            iter = a.erase(iter);
        } else {
            iter++;
        }
    }
     
    for (const auto &element : a) {
        cout<<element.first<<" : "<<element.second<<endl;
    }

    bool click = true, like =false, push = true, comment = false, follow=true,share=true,stay = 1.0, staytime_binary_pos=0.5;
    map<string, bool> multitask_labels = {{"click", click ? 1.0 : 0.0},
    {"like", like ? 1.0 : 0.0},
    {"push", push ? 1.0 : 0.0},
    {"comment", comment ? 1.0 : 0.0},
    {"follow", follow ? 1.0 : 0.0},
    {"share", share ? 1.0 : 0.0},
    {"stay", stay >= staytime_binary_pos ? 1.0 : 0.0}
   };

   for (const auto &element : multitask_labels) {
    cout<<element.first<<" : "<<element.second<<endl;
}


     
    return 0;
}