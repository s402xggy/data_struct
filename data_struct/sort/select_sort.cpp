#include <iostream>
/*
    简单选择排序：
        1、在未排序的序列中，找到最小（大）的元素，放到排序的起始位置。
        2、在从未排序的元素中继续寻找最小（大）的元素放在已排序的末尾。
        3、重复上述步骤，直到所有元素排序完毕。
*/
const int SIZE = 10;
void SimpleSelectSort(int arr[], int n);
int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    SimpleSelectSort(arr, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



    return 0;
}


void SimpleSelectSort(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}