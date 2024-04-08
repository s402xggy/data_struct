#include <iostream>
#include <string>

#include "stack.hpp"
#include "src/stack.cpp"

using std::cout;
using std::endl;

// 栈的应用：中缀表达式转换为后缀表达式。

// 1.仍然从做到右来处理数据。
// 2.当遇到左括号时忽略它
// 3.当遇到数值时，直接输出。
// 4.当遇到操作符时，将操作符号入栈。
// 5.当遇到右括号时，出栈栈顶的操作符

void CaculateRpn(std::string user_input, Stack<int> & stack);
void MidToLast(std::string mid_exp, std::string &last_exp);

int main() {
    Stack<int> stack(256);
    cout << "请输入算式的表达式: ";
    std::string user_input;
    std::getline(std::cin, user_input);
    std::string last_exp;
    MidToLast(user_input, last_exp);
    CaculateRpn(last_exp, stack);
    cout << "计算结果为: " << stack.Pop() << endl;
    return 0;
}

void CaculateRpn(std::string user_input, Stack<int> & stack) {
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
                    stack.Push((mark) - '0');
                    break;
            }
            mark = user_input[++i];
        }
}


void MidToLast(std::string mid_exp, std::string &last_exp) {
    Stack<char> stack(256);
    char mark = mid_exp[0];
    int i = 0;
    while (mark != '\0') {
        switch (mark)
        {
            case '+':
                stack.Push(mark);
                break;
            case '-':
                stack.Push(mark);
                break;
            case '*':
                stack.Push(mark);
                break;
            case '(':
                break;
            case ')':
                last_exp.push_back(stack.Pop());
                break;
            default:
                last_exp.push_back(mark);
                break;
        }
        mark = mid_exp[++i];
    }
}