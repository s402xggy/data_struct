#include <iostream>
#include "stack.hpp"
#include "src/stack.cpp"
using namespace std;

int main() {

    Stack<int> stack(256);
    stack.Push('a');
    stack.Push('b');
    stack.Push('c');
    while (!stack.IsEmpty()) {
        cout << stack.Pop() << " ";
    }
    cout << endl;
    return 0;
}