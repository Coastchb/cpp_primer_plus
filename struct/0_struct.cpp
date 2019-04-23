/**
 * Created by coast on 2019/4/22
 */
#include <iostream>
using namespace std;

struct Book {
    char title[20];
    char author[20];
    int price;
};

void print_book(const Book& b) {
  cout << "title:" << b.title << "\tauthor:" << b.author << "\tprice:" << b.price << endl;
}

int main(int argc, char* argv[]) {
  Book book1 = {"effecitve c++", "Zhang San", 30};
  print_book(book1);

  Book* book2 = new Book;
  strcpy(book2->title, "c++ primer");
  strcpy(book2->author, "Li Si");
  book2->price = 40;
  print_book(*book2);

  return 0;
}