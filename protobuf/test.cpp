/**
 * Created by coast on 2019/1/25
 */
#include <iostream>
#include <fstream>
#include <string>
#include "proto/addressbook.pb.h"
using namespace std;

void PromptForAddress(tutorial::Person* person) {
  cout << "Enter person ID number:";
  int id;
  cin >> id;
  person->set_id(id);
  cin.ignore(256, '\n');

  cout << "Enter name:";
  getline(cin, *person->mutable_name());

  cout << "Enter email address(blank for none):";
  string email;
  getline(cin, email);
  if (!email.empty()) {
    person->set_email(email);
  }

  while (true) {
    cout << "Enter a phone number (or leave blank to finish):";
    string number;
    getline(cin, number);
    if (number.empty()) {
      break;
    }

    tutorial::Person::PhoneNumber* phoneNumber = person->add_phones();
    phoneNumber->set_num(number);

    cout << "Is this a mobile, home or work phone?";
    string type;
    getline(cin, type);

    if (type == "mobile") {
      phoneNumber->set_type(tutorial::Person::MOBILE);
    } else if (type == "home") {
      phoneNumber->set_type(tutorial::Person::HOME);
    } else if (type == "work") {
      phoneNumber->set_type(tutorial::Person::WORK);
    } else {
      cout << "Unknown phone type,use default." << endl;
    }
  }

}
int main(int argc, char* argv[]) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage: " << argv[0] << "ADDRESSBOOK_FILE" << endl;
    return -1;
  }

  tutorial::AddressBook addressBook;

  {
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << " file not found. Create a new one" << endl;
    } else if (!addressBook.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book " << argv[1] << endl;
      return -1;
    }
  }

  PromptForAddress(addressBook.add_people());

  {
    fstream out(argv[1], ios::out | ios::trunc | ios::binary);
    if (!addressBook.SerializeToOstream(&out)) {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
  }
  google::protobuf::ShutdownProtobufLibrary();

  cout << "ok" << endl;
  return 0;
}