#include <iostream>
#include <cstdio>
#include <stdexcept>

using namespace std;

void func(int num) {
  if (num < 0) {
    throw out_of_range("less than zero.");
  } else {
    throw length_error("length error.");
  }
}

int main(int argc, char** argv) {
  try {
    func(1);
  } catch (out_of_range) {
    cout << "bad value" << endl; 
  //} catch (length_error) {
  //  cout << "good value" << endl; 
  } catch (exception& e) {
    //cout << "exception : " << e.what() << endl;
    fprintf(stderr, "%s\n", e.what());
  }

  return 0;
}
