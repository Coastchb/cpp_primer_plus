/**
 * Created by coast on 2019/4/20
 */
#include <iostream>

using namespace std;

bool binary_search_re(const int list[], const int& start,
  const int& end, const int& target) {
  if (start > end) {
    cout << target << " does not exist in the list\n";
    return false;
  }
  int mid = (start + end) / 2;
  if (list[mid] == target) {
    cout << target << " at " << mid << endl;
    return true;
  } else if (list[mid] < target) {
    return binary_search_re(list, mid+1, end, target);
  } else {
    return binary_search_re(list, start, mid - 1, target);
  }
}

bool binary_search(const int list[], const int& size, const int& target) {
  int start = 0, end = size;
  while (1) {
    int mid = (start + end) / 2;
    if (list[mid] == target) {
      cout << target << " at " << mid << endl;
      return true;
    } else if (list[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    if (start > end) {
      cout << target << " not in the list\n";
      return false;
    }
  }
}

int main(int argc, char* argv[]) {
  int list[] = {1,2,3,6,8,9,21,32};
  binary_search(list, 8, 10);
  binary_search(list, 8, 32);

  return 0;
}