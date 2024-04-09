#include <iostream>
#include "double_queue.hpp"
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
    Dqueue<char> queue(256);
    int n = str.size();
    int i = 0;
    while (n--) {
        queue.TailEnqueue(str[i]);
        i++;
    }
    while (!queue.IsEmpty())
    {
        char str1 = queue.HeadDequeue();
        if (!queue.IsEmpty()) {
            char str2 = queue.TailDequeue();
            if (str1 == str2)
                continue;
            else 
                return false;
        }
    }
    return true;
}
