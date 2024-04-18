#include <iostream>

int arr1[100] = {2, 3 ,90, 45, 24, 89, 66, 12, 35, 77};
int arr2[100] = {1, 5, 23, 44, 54, 58, 61, 65, 88, 93};

// 无序的线性，只能遍历查找。
int SqSearch(int arr[], int n, int x);
// 哨兵写法
int SqSearchGuard(int arr[], int n, int x);


// 有序的采用二分查找。
int BinarySearch(int arr[], int n, int x);
int RecursionBinarySearch(int arr[], int x, int low, int high);

int main() {
    int x = 77;
    int result = SqSearch(arr1, 10, x);
    if (result == -1) {
        std::cout << "未能找到在arr1中找到 " << x << std::endl;
    }
    else {
        std::cout << x << " 在arr1中的位置为 " << result << std::endl;
    }
    int y = 100;
    int result2 = SqSearchGuard(arr2, 10, y);
    if (result2 == 10) {
        std::cout << "未能找到在arr2中找到 " << y << std::endl;
    }
    else {
        std::cout << y << " 在arr2中的位置为 " << result2 << std::endl;
    }
    int z = 44;
    int result3 = BinarySearch(arr2, 10, z);
    if (result3 == -1) {
        std::cout << "未能找到在arr2中找到 " << z << std::endl;
    }
    else {
        std::cout << z << " 在arr2中的位置为 " << result3 << std::endl;
    }

    int m = 44;
    int result4 = RecursionBinarySearch(arr2, m, 0, 9);
    if (result4 == -1) {
        std::cout << "未能找到在arr2中找到 " << m << std::endl;
    }
    else {
        std::cout << m << " 在arr2中的位置为 " << result4 << std::endl;
    }

    return 0;
}

int SqSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) 
            return i;
    }
    return -1;
}

int SqSearchGuard(int arr[], int n, int x) {
    arr[n] = x;
    int i;
    for (i = 0; arr[i] != x; i++);
    return i ;
}


int BinarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (x == arr[middle]) 
            return middle;
        else if (x < arr[middle]) {
            high = middle - 1;
        }
        else if (x > arr[middle]) 
            low = middle + 1;
    }
    return -1;
}

int RecursionBinarySearch(int arr[], int x, int low, int high) {
    int middle = (low + high) / 2;
    if (low > high)
        return -1;
    if (x == arr[middle]) 
        return middle;
    else if (x < arr[middle])
        return RecursionBinarySearch(arr, x, low, middle - 1);
    else if (x > arr[middle])
        return RecursionBinarySearch(arr, x, middle + 1, high);
}

