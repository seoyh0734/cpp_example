#include <iostream>
#include <stdexcept>

class Heap {
  private:
   int* arr;
   unsigned int size;
   unsigned int maxSize;

   int currentIndex;
   public:
    Heap(int maxSize) {
     this->arr = new int[maxSize+1];
     this->size = 0;
     this->maxSize = maxSize;
   }

   ~Heap() {
     delete[] this->arr;
     this->arr = NULL;
   }

   void add(int element) {
     if (this->maxSize <= this->size) {
       throw std::runtime_error("oversize");
     }

     unsigned int index = this->size+1;

     this->arr[index]=element;
     unsigned int parent = index/2;

     std::cout << "parent : " << this->arr[parent] << " " << parent << std::endl;
     std::cout << "child : " << this->arr[index] << std::endl;

     while (parent != 0 && this->arr[parent] < this->arr[index]) {
       int temp = this->arr[parent];
       this->arr[parent] = this->arr[index];
       this->arr[index] = temp;

       index = parent;
       parent = index/2;
     }

     size++;
   }

   void print() {
     //print_node(1);

     unsigned int underLog = 0;
     int max = 1;
     while (max <= this->size) {
       max *= 2;
       underLog++;
     }

     std::cout << "depth : " << underLog << std::endl;

     for (unsigned int i=1; i<=this->size; i++) {
       std::cout << " " << this->arr[i] << " ";

       if (is_square(i+1)) {
         std::cout << std::endl;
       }
     }
   }

   bool is_square(int i) {
     int cmp = 1;
     while(i >= cmp) {
       if (cmp == i) {
         return true;
       }

       cmp *= 2;
     }

     return false;
   }

   void print_node(unsigned int index) {
     if (index > this->size) {
       return ;
     }

     std::cout << " " << this->arr[index] << " " << std::endl;

     print_node(index * 2);
     print_node(index * 2 + 1);
   }
};

int main(int argc, char** argv) {
  std::cout << "main()" << std::endl;

  Heap* heap = new Heap(100);
  heap->add(1);
  heap->add(0);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->add(3);
  heap->print();

  return 0;
}
