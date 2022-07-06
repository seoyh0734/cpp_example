#include <iostream>
#include <algorithm>
#include <vector>

void printSC(std::vector<int> v)
{
  for_each(v.begin(), v.end(), [](int i) -> void { std::cout << i << std::endl; });
}

void printIter(int a)
{
  std::cout << a << std::endl;
}

bool more10Iter(int a)
{
  return a  >= 10;
}

void copyTest()
{
  std::vector<int> arrA(3);
  for (int i=0; i<arrA.size(); i++)
  {
    arrA[i] = i * 10;
  }

  // copy
  {
    std::cout << "copy" << std::endl;
    std::vector<int> arrB(3);
    copy(arrA.begin(), arrA.end(), arrB.begin());
    for_each(arrA.begin(), arrA.end(), printIter);
    for_each(arrB.begin(), arrB.end(), printIter);
  }

  // copy_n
  {
     std::cout << "copy_n" << std::endl;
     std::vector<int> arrB(3);
     copy_n(arrA.begin(), 2, arrB.begin());
     for_each(arrA.begin(), arrA.end(), printIter);
     for_each(arrB.begin(), arrB.end(), printIter);
  }

  // copy_if
  {
     std::cout << "copy_if" << std::endl;
     std::vector<int> arrB(3);
     copy_if(arrA.begin(), arrA.end(), arrB.begin(), more10Iter);
     for_each(arrA.begin(), arrA.end(), printIter);
     for_each(arrB.begin(), arrB.end(), printIter);
  }
}

void moveTest()
{
  std::vector<int> arrA(10);
  transform(arrA.begin(), arrA.end(), arrA.begin(), [](int a)->int{ static int cnt = 1; return cnt++; });
  printSC(arrA);

  std::vector<int> arrB;

  //move(arrA.begin(), arrA.end(), arrB.begin());

  int a,b;
  a = 10;
  move(a,b);

}

int lambda()
{
  int b = 101;
  std::function<int(int)> f = [=, &b](int a)->int{  return a + b;};

  int c = f(10);

  std::cout << c << std::endl;

  return 0;
}

int main(int argc, char* argv[])
{
  copyTest();

  lambda();

  moveTest();

  return 0;
}

//using namespace std;
//
//void push_num(vector<int>& v, int i) {
//  v.push_back(i);
//}
//
//void print_vec(const vector<int> v) {
//  int cnt = 1;
//  for_each(v.begin(), v.end(), [&cnt] (int i) {
//    cout << cnt++ << "st = " << i << endl;
//  });
//}
//
//int add(int a, int b) {
//  return a + b;
//}
//
//int sub(int a, int b) {
//  return a - b;
//}
//
//int main(int argc, char** argv) {
//  vector<int> v;
//  vector<int> v2;
//
//  //push_num(v, 5);
//  //print_vec(v);
//
//  auto push_func = bind(push_num, std::ref(v), std::placeholders::_1);
//  auto show_func = bind(print_vec, std::placeholders::_1);
//
//  push_func(5);
//  push_func(6);
//  push_func(7);
//  push_func(8);
//  push_func(9);
//  show_func(v);
//
//  auto add_with_5 = bind(add, std::placeholders::_1, 5);
//  cout << add_with_5(10) << endl;
//
//  auto sub_with_3 = bind(sub, std::placeholders::_1, std::placeholders::_2);
//  cout << sub_with_3(10, 1) << endl;
//
//  return 0;
//}
