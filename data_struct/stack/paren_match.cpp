#include <iostream>
#include <string>

#include "stack.hpp"
#include "src/stack.cpp"

using std::cout;
using std::endl;

// 括号匹配：输出匹配的括号的位置，序号。
/*
    1. 遇到(入栈，此时入栈的数据为(在数组下的下标
    2. 遇到其他忽略
    3. 遇到)出栈。
*/

int ParenMatch(std::string user_input, int *res);
void Print(int *arr, int n);

int main() {
    Stack<int> stack(256);
    cout << "请输入算式的表达式: ";
    std::string user_input;
    std::getline(std::cin, user_input);
    int res[200];
    int num = ParenMatch(user_input, res);
    Print(res, num);

    return 0;
}

int ParenMatch(std::string user_input, int *res) {
    char mark = user_input[0];
    int i = 0, j = 0;
    Stack<int> stack(256);
    while (mark != '\0') {
        switch (mark) {
            case '(': 
                stack.Push(i);
                break;
            case ')':
                res[j++] = stack.Pop();
                res[j++] = i;
                break;
            default: 
                break;
        }
        mark = user_input[++i];

    }
    return j;
}

void Print(int *arr, int n) {
    int i = 0;
    cout << "匹配的括号位置序号为: ";
    while (i < n) {
        if (i % 2 == 0)
            cout << endl;
        cout << arr[i++] << " ";
    }
}
