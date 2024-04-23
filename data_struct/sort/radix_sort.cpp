#include <iostream>
/*
    基排序：

*/

const int SIZE = 16;
const int M = 10;
struct Node {
    int elem;
    Node *next;
    Node():next(nullptr){};
};


int ScoresSort(int value);
void RadixSort(int arr[], int size);
int SearchMaxbit(int arr[], int size);
int Bitnumber(int x, int bit);

int main() {
    int scores[SIZE]= {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88, 100};
    RadixSort(scores, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}



void RadixSort(int arr[], int size) {
    int max_bit = SearchMaxbit(arr, size);
    int j = 0;
    for (int k = 1; k <= max_bit; k++) {
        Node * bucket[M] = {nullptr};
        for (int i = 0; i < size; i++) {
            int index = Bitnumber(arr[i], k); // 1个位， 2为十位。
            Node *p = new Node;
            p->elem = arr[i];
            if (bucket[index] == nullptr) {
                bucket[index] = p;
                p->next = nullptr;
            }
            else {
                Node *point = bucket[index];
                Node *pre = nullptr;
                while (point != nullptr) {
                    pre = point;
                    point = point->next;
                }
                pre->next = p;
                p->next = point;
            }
        }
        for (int i = 0; i < M; i++) {
            if (bucket[i] == nullptr)
                continue;
            else {
                Node *point = bucket[i];
                while (point != nullptr)
                {
                    arr[j++] = point->elem; 
                    point = point->next;
                }
                
            }
        }
        j = 0;
    }
    

}

int SearchMaxbit(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    // 局部变量最好初始化
    int max_bit = 0;
    while (max) {
        max = max / 10;
        max_bit ++;
    }
    return max_bit;

}

int Bitnumber(int x, int bit) {
    int temp = 1;
    for (int i = 1; i < bit; i++) {
        temp *= 10;
    }
    return (x / temp) % 10;
}