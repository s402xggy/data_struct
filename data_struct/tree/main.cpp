#include "bin_tree.hpp"

int main() {
    Btree<char> btree;
    btree.PrintBtree(PreOrder<char>);
    cout << endl;
    btree.PrintBtree(MidOrder<char>);
    cout << endl;
    btree.PrintBtree(LastOrder<char>);
    cout << endl;



    return 0;
}