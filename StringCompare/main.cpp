#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  string min("19.168.0.0");
  string max("192.168.255.255");
  string test("192.168.57.101");

  if( test.compare(min) > 0 && test.compare(max) < 0)
    cout << "correct!" << endl;
  else 
    cout << "incorrect!" << endl;

  cout << "with min" << test.compare(min) << "with max" <<  test.compare(max) << endl;



  return 0;
}
