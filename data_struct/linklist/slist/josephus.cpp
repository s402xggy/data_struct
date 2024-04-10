#include "slist.hpp"
#include "loop_list.hpp"
using namespace std;

int n;
void Josephus(LoopList<int> &loop_list);
int main() {

    cout << "请输入人数n: ";
    cin >> n;
    // 循环链表实现功能测试
    LoopList<int> loop_list; 
    for (int i = 1; i <= n; i++)
        loop_list.InsertAtTail(i);
    loop_list.PrintSlist();
    Josephus(loop_list);


    






    return 0;
}

void Josephus(LoopList<int> &loop_list) {
    int k, m;
    cout << "请输入从第号开始报数k: ";
    cin >> k;
    cout << "请输入报数的数m: ";
    cin >> m;
    Node<int> *head = loop_list.GetHead();
    Node<int> *pre;
    for (int i = 0; i < k - 1; i++) {
        head = head->next;
    }
    if (m == 1) {
        while (n--) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    else {
        while (n--) {
            for (int j = 1; j <= m-1; j++) {
                pre = head->next;
            }
            cout << pre->data << " ";
            head->next = pre->next;
            head = pre->next;
        }
        
    }
     


}

