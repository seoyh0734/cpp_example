#include <iostream>
#include <stdio.h>
#include "ClassB.h"

// #define MYDEBUG(fmt, ...) { printf("[%s:%d] %s "fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); }

using namespace std;
 
static int testVar=1;

int main(int argc, char** argv) {
	ClassB *classB = new ClassB(1,2);
  testVar=3;
	//classA->printInfo();

	return 0;
}
