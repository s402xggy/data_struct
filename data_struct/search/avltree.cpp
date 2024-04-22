#include "avltree.hpp"
const int SIZE = 11;
int main() {
    int arr[SIZE] = {37, 22, 11, 82, 67, 9, 45, 91, 33, 52, 100};
    Avltree<int> btree(arr, SIZE);
    btree.PrintBtree(MidOrder<int>);
    cout << endl;
    btree.AvlsearchTreeDelete(DeleteAvltree<int>, 100);
    btree.PrintBtree(MidOrder<int>);
    cout << endl;
    btree.AvlsearchTreeDelete(DeleteAvltree<int>, 91);
    btree.PrintBtree(MidOrder<int>);
    cout << endl;

    return 0;
}