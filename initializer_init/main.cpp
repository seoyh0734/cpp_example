#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

template<typename T>
class Sample
{
  public:
    Sample(initializer_list<T> l) : v(l) {
      cout << "constructed with a" << l.size() << "-element list\n";
    }

    void append(initializer_list<T> l) {
      v.insert(v.end(), l.begin(), l.end());
    }

    void printV() {
      for(int val : v) {
        cout << val << endl;
      }
    }
    
    private:
      vector<int> v;
};

int main(int argc, char** argv) {
  Sample<int> sample = { 1, 2, 3, 4 };
  sample.append({ 5, 6, 7 });

  sample.printV();

  return 0;
}
