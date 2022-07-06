#include <iostream>
#include <stdexcept>

#include <csignal>
#include <execinfo.h>
#include <cstdlib>
#include <unistd.h>

void handler(int sig) {
  void *array[10];
  size_t size;

  size = backtrace(array, 10);

  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);

  exit(1);
}

void func1() {
  
  char* asd =NULL;
  //printf("%s\n", asd);

  throw std::runtime_error("");

}

void func2() {
  func1();
}

void func3() {
  func2();
}

int main(int argc, char** argv) {
  signal(SIGSEGV, handler);

  func3();

  return 0;
}
