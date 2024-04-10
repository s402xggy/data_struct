#ifndef __LOOP_LIST_HPP__
#define __LOOP_LIST_HPP__

#include "slist.hpp"

template <class T>
class LoopList{
    public:
        LoopList() {
            head_ = tail_ = nullptr;

        }
        ~LoopList() {

        delete []head_;
        delete []tail_;
        }
    public:
        void InsertAtTail(T d) {
            Node<T> *node = new Node<T>;
            node->data = d;
            node->next = nullptr;
            if (head_ == nullptr) {
                head_ = tail_ = node;
                tail_->next = head_;
            }
            else {
                tail_->next = node;
                tail_ = node;
                tail_->next = head_;
            }
        }
        void Insert(T d, int pos) {
            if (pos == 0) {
                Node<T> *node = new Node<T>;
                node->data = d;
                node->next = head_;
                head_ = node;
                tail_->next = head_;
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
                tail_->next = head_;
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
                        tail_->next = head_;
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
            while (node->next != head_) {
                if (node->data == d)
                    return i;
                else {
                    i++;
                    node = node->next;
                }
            }
            if (node->data == d)
                return ++i;
            return -1;
        }

        void PrintSlist() {
            Node<T>* node = head_;
            while (node->next != head_) {
                cout << node->data << " ";
                node = node->next;
            }
            cout << node->data << endl;
        }

        Node<T> * GetHead() {
            return head_;
        }

        Node<T> * GetTail() {
            return tail_;
        }
    private:
        Node<T> *head_;
        Node<T> *tail_;
};















#endif
