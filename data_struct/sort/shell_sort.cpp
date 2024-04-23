#include <iostream>
#include <vector>
// 希尔排序：
/*
    通过设定不同的增量，得到一个相对有序的序列。

    最后进行一次增量为1的排序。
*/


const int SIZE = 10;
const int MAX = 100;
void StraightInsertSort(int sort[], int size);
void ShellSort(int shell_arr[], int size, const std::vector<int> &di);
void ShellInsertSort(int arr[], int n, int di);

int main() {
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    int sort[MAX + 1];
    for (int i = 0; i < SIZE; i++) {
        sort[i+1] = arr[i];
    }
    std::vector<int> di = {5, 3, 1};
    ShellSort(sort, SIZE, di);
    for (int i = 0; i < SIZE; i++) {
        arr[i] = sort[i + 1];
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << sort[i] << " ";
    }


    return 0;
}

// void StraightInsertSort(int sort[], int size) {
//     int i, j;
//     for (i = 2; i < size; i++) {
//         if(sort[i - 1] > sort[i]) {
//             sort[0] = sort[i];
//             sort[i] = sort[i - 1];
//             for (j = i - 2; sort[j] > sort[0]; j--) {
//                 sort[j + 1] = sort[j];
//             }
//             sort[j + 1] = sort[0];
//         }
//     }
// }


void ShellSort(int shell_arr[], int size, const std::vector<int> &di) {
    for (int i = 0; i < di.size(); i++)
        ShellInsertSort(shell_arr, size, di[i]);
}

void ShellInsertSort(int sort[], int size, int di) {
    int i, j;
    for (i = 1 + di; i < size; i++) {
        if(sort[i - di] > sort[i]) {
            sort[0] = sort[i];
            sort[i] = sort[i - di];
            for (j = i - (2 * di); j > 0 && sort[j] > sort[0]; j -= di) {
                sort[j + di] = sort[j];
            }
            sort[j + di] = sort[0];
        }
    }
}



