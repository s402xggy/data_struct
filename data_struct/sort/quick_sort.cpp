#include <iostream>

/*
快速排序：
    1、分解：选择其中一个元素。将序列分为两个部分。
    {
        基准的选择： 取第一个
                    取中间元素
                    取最后一个
                    .....
    }
    此时，选取第一个元素。
    2、治理
    3、合并

*/

const int SIZE = 10;
const int MAX = 100;

void QuickSort(int arr[], int start_pos, int end_pos);

int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    QuickSort(arr, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void QuickSort(int arr[], int start_pos, int end_pos) {
    int i = start_pos;
    int j = end_pos;
    while (i < j)
    {
        while (arr[i] < arr[j] && i < j)
            j--;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        while (arr[i] <= arr[j] && i < j) 
            i++;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    if (i - 1 < start_pos)
        QuickSort(arr, start_pos, i - 1);
    if (j + 1 < end_pos) 
        QuickSort(arr, i+1, end_pos);


}

