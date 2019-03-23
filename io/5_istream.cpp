//
// Created by coast on 19-3-22.
//

#include <string>
#include <fstream>
#include <iostream>
using  namespace std;

template<class T, int N> class scoped_fixed_array {
private:
    T * ptr_;
    size_t size_;
    scoped_fixed_array(scoped_fixed_array const &);
    scoped_fixed_array & operator= (scoped_fixed_array const &);
    typedef scoped_fixed_array<T, N> this_type;

public:
    typedef T element_type;
    explicit scoped_fixed_array()
            : ptr_(new T[N]), size_(N) {}
    virtual ~scoped_fixed_array() { delete [] ptr_; }
    size_t size() const { return size_; }
    T & operator*() const   { return *ptr_; }
    T * operator->() const  { return ptr_;  }
    T * get() const         { return ptr_;  }
    T & operator[](size_t i) const   { return ptr_[i]; }
};

bool read(std::istream *is) {
    scoped_fixed_array<char, 8192> line;
    //clear();

    for (;;) {
        if (!is->getline(line.get(), line.size())) {
            is->clear(std::ios::eofbit|std::ios::badbit);
            return true;
        }
        if (line[0] == '\0' || line[0] == ' ' || line[0] == '\t') {
            break;
        }
        cout << line.get() << endl << endl;
        /*
        if (!add(line.get())) {
            return false;
        }*/
    }

    return true;
}

int main(){
    string filename = "files/5.txt";
    istream* is = new ifstream(filename.c_str());
    read(is);

    return 0;
}