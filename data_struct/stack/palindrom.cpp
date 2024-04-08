#include <iostream>
#include "stack.hpp"
#include "src/stack.cpp"
using namespace std;

/*
    // 栈的应用：回文判定
    1. 求出字符串的长度， 将前一半的字符依次入栈。
    2. 如果栈不为空，出栈栈顶的元素， 将其与后半部分进行比较，如果字符串的
       长度为奇数，需要跳过中心点元素，比较中心点后面的元素，如果比较的是相
       等的，则一直比较，直到栈为空， 如果出现不等，立刻停止比较，返回非回文。
*/

bool IsPalindrom(const std::string &str);


int main() {
    Stack<int> stack(256);
    std::string str;
    cout << "请输入一个字符串: " << endl;
    getline(cin, str);
    if (IsPalindrom(str)) 
        cout << str << " 是回文字符串" << endl;
    else 
        cout << str << " 不是回文字符串" << endl;
    return 0;
}

bool IsPalindrom(const std::string &str) {
    Stack<char> stack(256);
    int n = str.size();
    int i = 0;
    while (i < (n / 2))
    {
        stack.Push(str.at(i));
        i++;
    }
    i = n % 2;
    n = n / 2;
    if (i == 0) {
        while (!stack.IsEmpty()) {
            if (stack.Pop() == str[n]) {
                n++;
                continue;
            } else 
                return false;
        }
    } 
    else {
        n++;
        while (!stack.IsEmpty()) {
            if (stack.Pop() == str[n]) {
                n++;
                continue;
            } else 
                return false;
        }
    } 
    return true;
}
