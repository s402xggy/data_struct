#ifndef __SLIST_HPP__
#define __SLIST_HPP__
#include <iostream>
using std::cout;
using std::endl;

/*
    链表的头指针非常重要，通过头指针访问，遍历后续元素。
    头指针指向头节点， 尾指针的后继节点为nullptr;
    1. 链表的基本操作：
        创建链表。
        任意点插入节点，需要遍历链表，确定插入的位置。
*/

template <class T>
struct Node{
    T data;
    Node<T> *next;
};

template <class T>
class Slist{
    public:
        Slist() {
            head_ = tail_ = nullptr;
        }
        ~Slist() {
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_ = nullptr;
        }
    public:
        void InsertAtTail(T d) {
            Node<T> *node = new Node<T>;
            node->data = d;
            node->next = nullptr;
            if (head_ == nullptr)
            head_ = tail_ = node;
            else {
                tail_->next = node;
                tail_ = node;
            }
        }
        void Insert(T d, int pos) {
            if (pos == 0) {
                Node<T> *node = new Node<T>;
                node->data = d;
                node->next = head_;
                head_ = node;
            }
            else {
                int i = 0;
                Node<T> *pre = head_;
                while (i < pos - 1)
                {
                    if (pre == nullptr)
                        return ;
                    pre = pre->next;
                    i++;
                }
                if (pre->next == nullptr)
                    InsertAtTail(d);
                else {
                     Node<T> * node = new Node<T>;
                    node->data = d;
                    node->next = pre->next;
                    pre->next = node;
                }
            }
        }

        void DeleteNode(int pos) {
            Node<T> * pre = head_;
            if (pos == 0) {
                head_ = head_->next;
                delete pre;
            } else {
                int i = 0;
                while (i < pos - 1) {
                    if (pre == nullptr)
                        return;
                    pre = pre->next;
                    i++;
                }
                if (pre->next == nullptr) 
                    return;
                else {
                    Node<T> *pos_node = pre->next;
                    if (pos_node->next == nullptr) {
                        tail_ = pre;
                        tail_->next = nullptr;
                        delete pos_node;
                    } else  {
                        pre->next = pos_node->next;
                        delete pos_node;
                    }
                }

            }
        }

        int Search(T d) {
            Node<T> *node = head_;
            int i = 0;
            while (node) {
                if (node->data == d)
                    return i;
                else {
                    i++;
                    node = node->next;
                }
            }
            return -1;
        }

        void PrintSlist() {
            Node<T>* node = head_;
            while (node) {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }

    private:
        Node<T> *head_;
        Node<T> *tail_;
};









#endif
