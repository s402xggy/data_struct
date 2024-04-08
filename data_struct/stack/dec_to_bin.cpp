#include <iostream>
#include "stack.hpp"
#include "src/stack.cpp"
using namespace std;

/*
    // 栈的应用： 十进制数转换为二进制数。
    1. 判断 if (n == 0) return;
    2. 十进制数为n , 求余数 n % 2，并将其放入栈， 更新 n = n / 2;
    3. 当 n == 0 时退出循环
    4. 将栈中元素出栈
*/

void DecToBin(int dec, Stack<int> &stack);

int main() {

    cout << "请输入一个需要转换为二进制数的十进制整数: " << endl;
    int dec;
    std::string dec_str;
    getline(cin, dec_str);
    dec = std::stoi(dec_str);
    Stack<int> stack(256);
    DecToBin(dec, stack);
    while (!stack.IsEmpty()) {
        cout << stack.Pop();
    }
    cout << endl;
    return 0;
}

void DecToBin(int dec, Stack<int> &stack) {
    if (dec == 0)
        stack.Push(dec);
    else {
        int n = dec;
        while (n != 0) {
            stack.Push(n % 2);
            n = n / 2;
        }
    }
}