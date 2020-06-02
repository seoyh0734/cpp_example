#include <iostream>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

using namespace std;

class A {
 public:
  int* arr_;
  int size_;

  A() {
    size_ = 10;
    init();
  }

  A(int size) {
    size_ = size;
    init();
  }

  ~A() {
    cout << "destroy A" << endl;
    delete[] arr_;
  }

  int operator [] (int index) {
    if (index >= size_) {
      throw out_of_range("out_of_range");
    }
    return arr_[index]; 
  }

 private:
  void init() {
    int cnt = 0;
    arr_ = new int[size_];
    transform(arr_, arr_+size_, arr_, [&cnt](int i) {
        return ++cnt;
    });
  }
};

int main(int argc, char** argv) {
  shared_ptr<A>* a1 = new shared_ptr<A>(new A(10));
  shared_ptr<A> a2 = *a1;
  weak_ptr<A> a3 = *a1;

  cout << (**a1)[1] << endl;
  delete a1;
  cout << (*(shared_ptr<A>)a3)[94] << endl;

  return 0;
}
