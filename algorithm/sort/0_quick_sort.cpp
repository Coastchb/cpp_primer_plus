 /*
 * Created by coast on 2019/4/27
 */
#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int quick_iter(int list[], int p, int q, int tmp) {
  while(p != q) {
   while(list[q] >= tmp && q > p)
    q--;
   if(q < p)
    break;

   list[p] = list[q];

   while(list[p] <= tmp && p < q)
    p++;

   if(p == q)
    break;

   list[q] = list[p];
  }
  list[p] = tmp;
  return p;
}

bool quick_sort(int list[], int start, int end) {
 if(start >= end)
  return true;

 int tmp = list[start];
 int p = quick_iter(list, start, end, tmp);
 if(! quick_sort(list, start, p - 1))
  return false;
 if(! quick_sort(list, p + 1, end))
  return false;

 return true;
}


bool quick_sort(int list[], int size) {
 stack<tuple<int,int>> sub_list;
 sub_list.push(make_pair(0, size - 1));
 while(! sub_list.empty()) {
  int start, end;
  tie (start,end) = sub_list.top();
  sub_list.pop();
  int tmp = list[start];
  int tmp_pos = quick_iter(list, start, end, tmp);
  if(start < tmp_pos - 1)
   sub_list.push(make_pair(start,tmp_pos-1));
  if(tmp_pos + 1  < end)
   sub_list.push(make_pair(tmp_pos+1, end));
 }
 return true;
}

int main(int argc, char* argv[]) {
 int list1[] = {1, 20, 30, 21, 3, 4, 14, 60, 24};
 int list2[] = {1, 20, 30, 21, 3, 4, 14, 60, 24};

 quick_sort(list1, 0, 8);
 for(auto x: list1)
  cout << x << "\t";
 cout << endl;

 quick_sort(list2, 9);
 for(auto x: list2)
  cout << x << "\t";
 cout << endl;
}
