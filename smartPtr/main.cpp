#include <iostream>
#include <vector>
#include <memory>

class A {
 public:
  int num_;
  A() {
    printf("construct!\n");
    num_ = 0;
  }

  void printInfo() {
    printf("num_ = %d\n", num_);
  }
  
  ~A() {
    printf("destruct!\n");
  }
};

int main(int argc, char** argv) {
  printf("----==== start program ====----\n\n");

  A* a = new A();
  a->printInfo();
  delete a;

  std::unique_ptr<A> ptr(new A());
  ptr->printInfo();

  std::vector<std::unique_ptr<A>> v;
  printf("size = %d\n", v.size());
  v.push_back(std::move(ptr));
  printf("size = %d\n", v.size());
  //ptr->printInfo(); // Segmentation fault 
  v.emplace_back(new A());
  printf("size = %d\n", v.size());
  v[0]->printInfo(); 
  v[1]->printInfo();
  
  ptr = std::move(v[0]); 
  ptr->printInfo();

  //v[0]->printInfo(); Segmentation faule
  v[1]->printInfo();
 
  printf("\n----==== end program ====----\n"); 
  return 0;
}
