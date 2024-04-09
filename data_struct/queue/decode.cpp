#include <iostream>
#include <vector>
#include "queue.hpp"

using namespace std;

void Decode(const string &input, vector<char> & vec);
int main() {
    cout << "请输入一个加密后的字符串: ";
    vector<char> vec;
    string input;
    getline(cin, input);
    Decode(input, vec);
    cout << "解密后的字符串为: ";
    for (const auto &elem: vec)
        cout << elem;
    cout << endl;
    return 0;
}


void Decode(const string &input, vector<char> & vec) {
    Queue<char> queue(256);
    for (int i = 0; i < input.size(); i++) {
        queue.Enqueue(input[i]);
    }
    while (!queue.IsEmpty()) {
        vec.push_back(queue.Dequeue());
        queue.Enqueue(queue.Dequeue());
 
    }
}