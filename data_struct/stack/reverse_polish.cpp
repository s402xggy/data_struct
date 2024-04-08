#include <iostream>
#include <string>

#include "stack.hpp"
#include "src/stack.cpp"

using std::cout;
using std::endl;


int main() {
    Stack<int> stack(256);
    cout << "请输入算式的逆波兰表示: ";
    std::string user_input;
    std::getline(std::cin, user_input);

    char mark = user_input[0];
    int i = 0;

    int a, b;
    while (mark != '\0') {
        switch (mark)
        {
            case '+': 
                a = stack.Pop();
                b = stack.Pop();
                stack.Push(a + b);
                break;
            case '-': 
                a = stack.Pop();
                b = stack.Pop();
                stack.Push(b - a);
                break;
            case '*': 
                a = stack.Pop();
                b = stack.Pop();
                stack.Push(a * b);
                break;
            default:
                stack.Push(mark - '0');
                break;
        }
        mark = user_input[++i];
    }
    cout << "计算结果为: " << stack.Pop() << endl;
    return 0;
}

