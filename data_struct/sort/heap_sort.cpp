#include <iostream>

const int SIZE = 10;
void HeapSort(int arr[], int size);

void Sink(int arr[], int k, int n);
void Swap(int *p1, int *p2);
/*
    堆排序：
    完全二叉树{
        除了最下一层外，每一层都是满的，
        最下一层的节点三从左到右的。
    }
    数组中的每一个元素的序号和完全二叉树的序号对应。
    1、建立初始堆（大顶堆，最大值在堆顶上）。 完全二叉树的最大值位于堆顶。
    2、
*/

int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    HeapSort(arr, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void HeapSort(int arr[], int size) {
    for (int i = (size - 1)/ 2; i >= 0; i--) {
        Sink(arr, i, size);
    }
    while (size > 0) {
        Swap(&arr[0], &arr[size--]);
        Sink(arr, 0, size);
    }
}


void Sink(int arr[], int k, int n) {
    int j = 2 * k + 1;
    if (j > n)
        return ;
    else {
        if (j < n && arr[j] < arr[j + 1]) {
            j++;
        }
        if (arr[k] < arr[j]) {
            Swap(&arr[k], &arr[j]);
        }
        k = j;
        Sink(arr, k, n);
    }

}

void Swap(int *p1, int *p2) {
    int temp; 
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}