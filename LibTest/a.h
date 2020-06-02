class A {
 public:
  int num_;
  A();
  void printA();
};
extern "C" {
A* create();
void destroy(A* a);
void printA_(A* a);
}
