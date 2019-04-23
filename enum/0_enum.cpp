/**
 * Created by coast on 2019/4/19
 */
#include <iostream>
using namespace std;

enum dayEnum {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
  dayEnum day1;
  day1 = dayEnum(4);
  cout << day1 << endl;

  if (day1 == 4 ) {
    cout << "Happy Firday!\n";
  } else {
    cout << "Not Friday yet!\n";
  }

  dayEnum  day2 = Saturday;
  cout << day2 << endl;
  int a = Friday;
  cout << a << endl;

  a = day2 + 1;
  cout << a << endl;

  dayEnum day3 = dayEnum(1+1);
  dayEnum day4 = dayEnum(Monday + 1);
  dayEnum day5 = dayEnum(Monday + Tuesday);
  //day5++;
  day5 = dayEnum(day5 + 1);

  dayEnum day6 = dayEnum(7);
  dayEnum day7 = day6;
  cout << "dayEnum(7): " << day6 << endl;

}