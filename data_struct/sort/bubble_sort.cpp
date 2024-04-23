#include <iostream>

void BubbleSort(int arr[], int n);

const int SIZE = 10;
const int MAX = 100;
int main() {

    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
    int sort[MAX + 1];

    BubbleSort(arr, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void BubbleSort(int arr[], int n) {
    if (n == 0)
        return ;
    else  {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        BubbleSort(arr, --n);
    }

}