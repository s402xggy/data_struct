#include <iostream>
#include "queue.hpp"

using std::cout;
using std::endl;

int main() {
    Queue<char> queue(10);
    while (!queue.IsFull()) {
      queue.Enqueue('y');
      queue.Enqueue('x');
      queue.Enqueue('g');
      queue.Enqueue('g');
    }
    while (!queue.IsEmpty())
    {
      cout << queue.Dequeue();
    }
    cout << endl;    


    return 0;
}