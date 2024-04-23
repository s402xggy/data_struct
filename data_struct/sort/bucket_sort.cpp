#include <iostream>
#include "link.h"
/*
    桶排序：
        将待排序的序列放入不同的范围区间（桶）， 桶的范围和待排序列应该有一个映射关系。
        映射关系： 例如成绩： 65 / 10 = 6; 则可以放入6号桶。
        分别给每个桶排序。
        适用于数据分配均匀的情况。
*/

const int SIZE = 15;
const int M = 10;
struct Node {
    int elem;
    Node *next;
    Node():next(nullptr){};
};

void BucketSort(int arr[], int size);
void InsertBucket(Node * bucket[], int value);
int ScoresSort(int value);

int main() {
    int scores[SIZE]= {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88};
    BucketSort(scores, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void BucketSort(int arr[], int size) {
    Node * bucket[M] = {nullptr};
    int j = 0;
    for (int i = 0; i < size; i++) {
        InsertBucket(bucket, arr[i]);
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

}

void InsertBucket(Node * bucket[], int value) {
    int index = ScoresSort(value);
    Node * node = new Node;
    node->elem = value;
    node->next = nullptr;
    if (bucket[index] == nullptr || bucket[index]->elem > value) {
        node->next = bucket[index];
        bucket[index] = node;
    }
    else {
        Node *point = bucket[index];
        Node *pre;
        while (point != nullptr && point->elem <= node->elem) {
            pre = point;
            point = point->next;
        }
        pre->next = node;
        node->next = point;
    }

}

int ScoresSort(int value) {
    return value / 10;
}