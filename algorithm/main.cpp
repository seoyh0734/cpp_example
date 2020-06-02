#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void push_num(vector<int>& v, int i) {
  v.push_back(i);
}

void print_vec(const vector<int> v) {
  int cnt = 1;
  for_each(v.begin(), v.end(), [&cnt] (int i) {
    cout << cnt++ << "st = " << i << endl;
  });
}

int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

int main(int argc, char** argv) {
  vector<int> v;
  vector<int> v2;

  //push_num(v, 5);
  //print_vec(v);

  auto push_func = bind(push_num, std::ref(v), std::placeholders::_1);
  auto show_func = bind(print_vec, std::placeholders::_1);

  push_func(5);
  push_func(6);
  push_func(7);
  push_func(8);
  push_func(9);
  show_func(v);

  auto add_with_5 = bind(add, std::placeholders::_1, 5);
  cout << add_with_5(10) << endl;

  auto sub_with_3 = bind(sub, std::placeholders::_1, std::placeholders::_2);
  cout << sub_with_3(10, 1) << endl;

  return 0;
}
