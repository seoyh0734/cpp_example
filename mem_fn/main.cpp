#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class A {
 public:
  int id_;
  int num_;

  A(int id) {
    id_ = id;
    num_ = id;
   }

  void print() {
    cout << "id : "<< id_ << " num_ = " << num_ << endl;
  }

  int getId() {
    return this->id_;
  }

};

int main(int argc, char** argv) {
  vector<A> v;
  int cnt = 1;
  v.push_back(A(cnt++));
  v.push_back(A(cnt++));
  v.push_back(A(cnt++));
  v.push_back(A(cnt++));
  v.push_back(A(cnt++));

  cout << "v.size = " << v.size() << endl;

  for_each(v.begin(), v.end(), [] (A a) {
    a.print();
  });

  int* ids = new int[v.size()];

  //std::function<int(A&)> sz_vec = &A::getId;
  //transform(v.begin(), v.end(), ids, sz_vec);
  
  transform(v.begin(), v.end(), ids, std::mem_fn(&A::getId));


  for_each(ids, ids+(v.size()), [] (int i) {
    cout << i << endl;
  });
  
  return 0;
}
