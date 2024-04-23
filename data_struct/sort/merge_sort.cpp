#include <iostream>

/*
    合并排序：
        分解：将待排序的序列分解为两个子序列（一直分解为一个元素）（递归分解）
        治理：对两个子序列进行分别排序。
        合并：将所有子序列进行合并为一个有序序列。


*/
const int SIZE = 10;
void DivideMerge(int arr[], int start, int end);
void MergeSort(int arr[], int start, int mid, int end);

int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    DivideMerge(arr, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}


void DivideMerge(int arr[], int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        DivideMerge(arr, start, mid);
        DivideMerge(arr, mid + 1, end);
        MergeSort(arr, start, mid, end);
    }
    else
        return ;
}

void MergeSort(int arr[], int start, int mid, int end) {
    int i = 0, j = 0, k = start;
    int n1 = (mid - start) + 1;
    int n2 = (end - (mid + 1)) + 1;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }   
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }
        else 
            arr[k++] = right[j++];
    }
    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
}
