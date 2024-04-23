#include <iostream>

//
const int SIZE = 10;
const int MAX = 100;

void StraightInsertSort(int sort[], int size);



int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    int sort[MAX + 1];
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++) {
        sort[i+1] = arr[i];
    }
    StraightInsertSort(sort, SIZE);
    for (int i = 0; i < SIZE; i++) {
        arr[i] = sort[i + 1];
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}


void StraightInsertSort(int sort[], int size) {
    int i, j;
    for (i = 2; i < size; i++) {
        if(sort[i - 1] > sort[i]) {
            sort[0] = sort[i];
            sort[i] = sort[i - 1];
            for (j = i - 2; sort[j] > sort[0]; j--) {
                sort[j + 1] = sort[j];
            }
            sort[j + 1] = sort[0];
        }
    }
}