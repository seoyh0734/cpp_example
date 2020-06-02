#include <iostream>

using namespace std;

class RingBuffer {
 private :
  int* queue;
  int queue_size;
  int queue_rotation;
  int head_pos;
  int tail_pos;

 public :
  RingBuffer(int size) {
    std::cout << "Create Ring Buffer (" << size << ")" << std::endl;
    queue_size = size;
    queue_rotation = size + 1;
    queue = new int[queue_size];
    head_pos = 0;
    tail_pos = 0;
  }

  int put(int data) {
    if (head_pos == ((tail_pos + 1) % queue_rotation)) {
      cout << "RingBuffer is full." << endl;
      return -1;
    }

    queue[tail_pos] = data;
    tail_pos = (tail_pos + 1) % queue_rotation;

    return 0;
  }

  int get(int *buf) {
    if (head_pos == tail_pos) {
      cout << "RingBuffer is empty." << endl;
      return -1;
    }

    *buf = queue[head_pos];

    head_pos = (head_pos + 1) % queue_rotation;

    return 0;
  }

  void printQueue() {
    cout << "queue" << endl;
    for (int i=head_pos; i!=tail_pos; i=(i+1)%queue_rotation) {
      cout << queue[i] << " ";
    }
    cout << endl;
  }
};

int main(int argc, char** argv) {
  RingBuffer ringBuf(100);
  int* buf = new int;
  for (int i=0; i<100; i++)
    ringBuf.put(i);
  ringBuf.put(1);
  ringBuf.put(2);
  ringBuf.put(3);
  ringBuf.printQueue();
  return 0;
}
