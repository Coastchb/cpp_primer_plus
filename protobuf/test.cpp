/**
 * Created by coast on 2019/1/25
 */
#include <iostream>
#include <fstream>
#include <string>
#include "proto/addressbook.pb.h"
using namespace std;

void PromptForAddress(tutorial::Person person) {
  cout << "Enter person ID number:";
  int id;
  cin >> id;
  person.set_id(id);
  cin.ignore(256, '\n');

  cout << "Enter name:";
  getline(cin, *person.mutable_name());

  cout << "Enter email address(blank for none):";
  string email;
  getline(cin, email);
  if (!email.empty()) {
    person.set_email(email);
  }

  while (true) {
    cout << "Enter a phone number (or leave blank to finish):";
    string number;
    getline(cin, number);
    if (number.empty()) {
      break;
    }

    tutorial::Person::PhoneNumber* phoneNumber = person.add_phones();
    phoneNumber->set_num(number);

    cout << "Is this a "

  }

}
int main() {
  cout << "ok" << endl;
}