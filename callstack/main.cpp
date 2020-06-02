#include <iostream>
#include <execinfo.h>
#include <signal.h>


using namespace std;

#define SIZE 100

void func1(int sig) {
  cout << "func1" << endl;
  int nptrs;
  void *buffer[100];
  char **strings;

  nptrs = backtrace(buffer, SIZE);
  cout << "backtrace() returned " << nptrs << " addresses" << endl;

  strings = backtrace_symbols(buffer, nptrs);
  if (strings == NULL) {
    exit(-1);
  }

  for (int i = 0; i < nptrs; i++) {
    cout << strings[i] << endl;
  }

  delete[] strings;
  exit(1);
}

void func2() {
  cout << "func2" << endl;
  int *foo = (int*) -1;
  printf("%d\n", *foo);
}

void func3() {
  cout << "func3" << endl;
  func2();
}

int main(int argc, char** argv) {
  signal(SIGSEGV, func1);
  func3();

  return 0;
}
