#include <iostream>


const int SIZE = 12;
const int M = 15;
int InsertHashTable(int HT[], int key);
int Hash(int key);
int LineDetect(int HT[], int index, int key);
void PrintHashTable(int HT[], int m);
int SearchHashTable(int HT[], int num);

int main() {

    int arr[SIZE] = {14, 36, 42, 38, 40, 15, 19, 12, 51, 65, 34, 25};
    int HT[M] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1, -1, -1};

    for (int i = 0; i < SIZE; i++) {
        if(!InsertHashTable(HT, arr[i])) {
            std::cout << "哈希表创建失败！！！" << std::endl;
        }
    }
    PrintHashTable(HT, SIZE);
    int elem = 65;
    int pos = SearchHashTable(HT, elem);
    if (pos == -1) {
        std::cout << "哈希表中没有找到元素: " << elem << std::endl;
    }
    else {
        std::cout << "哈希表中找到元素: " << elem << " 在哈希表位置： " << pos << std::endl;
    }

    return 0;
}

int InsertHashTable(int HT[], int key) {
    int index = Hash(key);
    if (HT[index] == -1) {
        HT[index] = key;
        return 1;
    } 
    else {
       int Hi = LineDetect(HT, index, key);
       if (Hi != -1) {
            HT[Hi] = key;
            return 1;
       }
    }
    return 0;
}

int Hash(int key) {
    return key % 13;
}

int LineDetect(int HT[], int index, int key) {
    int res;
    for (int di = 0; di < M; di++) {
        res = (index + di) % M;
        if (HT[res] == -1)
            return res;
        else if (HT[res] == key)
            return res;
    }
    return -1;
}

void PrintHashTable(int HT[], int m) {
    for (int i = 0; i < m; i++) {
        std::cout << HT[i] << " ";
    }
    std::cout << std::endl;
}

int SearchHashTable(int HT[], int num) {
    int index = Hash(num);
    if (HT[index] == -1)
        return -1;
    else if (HT[index] == num)
        return index;
    else {
        int Hi = LineDetect(HT, index, num);
        if (HT[Hi] == num)
            return Hi;
        else 
            return -1;
    }

}