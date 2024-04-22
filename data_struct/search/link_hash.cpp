#include <iostream>

const int SIZE = 12;
const int M = 15;

struct Node{
    int elem;
    Node *next;
};

void InsertHashTable(Node *HT[], int key);
int Hash(int key);
void ShowHashTable(Node *HT[], int size);
int SearchHashTable(Node *HT[], int size, int num);

int main() {

    int arr[SIZE] = {14, 36, 42, 38, 40, 15, 19, 12, 51, 65, 34, 25};
    Node * HT[M] = {nullptr};

    for (int i = 0; i < SIZE; i++) {
        InsertHashTable(HT, arr[i]);
    }

    ShowHashTable(HT, M);
    std::cout << SearchHashTable(HT,M, 14) << std::endl;; 
    return 0;
}

void InsertHashTable(Node *HT[], int key) {
    int index = Hash(key);
    Node * p = new Node;
    p->elem = key;
    p->next = HT[index];
    HT[index] = p;
}


int Hash(int key) {
    return key % 13;
}

void ShowHashTable(Node *HT[], int size) {
    Node *temp;
    for (int i = 0; i < size; i++) {
        temp = HT[i];
        while (temp)
        {
            std::cout << temp->elem << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int SearchHashTable(Node *HT[], int size, int num) {
    Node *temp;
    for (int i = 0; i < size; i++) {
        temp = HT[i];
        while (temp)
        {
            if(temp->elem == num)
                return i;
            temp = temp->next;
        }
    }
    return -1;
}