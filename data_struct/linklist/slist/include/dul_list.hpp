#ifndef __DUL_LIST_HPP__
#define __DUL_LIST_HPP__

template<class T>
struct Dnode
{   
    Dnode<T> *pre;
    Dnode<T> *next;
    T data;
};

template <class T>
class Dlist{
    public:
        Dlist() {
            head_ = tail_ = nullptr;
        }
        ~Dlist() {
        delete []head_;
        delete []tail_;
        }
    public:
        void InsertAtTail(T d) {
            Dnode<T> *node = new Dnode<T>;
            node->data = d;
            node->pre = nullptr;
            node->next = nullptr;
            if (head_ == nullptr) {
                head_ = tail_ = node;
            }
            else {
                node->pre = tail_;
                tail_->next = node;
                tail_ = node;
            }
        }
        void Insert(T d, int pos) {
            if (pos == 0) {
                Dnode<T> *node = new Dnode<T>;
                node->pre = nullptr;
                node->data = d;
                node->next = head_;
                head_->pre = node;
                head_ = node;
            }
            else {
                int i = 0;
                Dnode<T> *pre = head_;
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
                    Dnode<T> * node = new Dnode<T>;
                    node->data = d;
                    node->pre = pre;
                    node->next = pre->next;
                    pre->next->pre = node;
                    pre->next = node;
                }
            }
        }

        void DeleteNode(int pos) {
            Dnode<T> * pre = head_;
            if (pos == 0) {
                head_ = head_->next;
                head_->pre = nullptr;
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
                        pre->next->pre = pre;
                        delete pos_node;
                    }
                }

            }
        }

        int Search(T d) {
            Dnode<T> *node = head_;
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
            Dnode<T>* node = head_;
            while (node) {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }

        Dnode<T> * GetHead() {
            return head_;
        }

        Dnode<T> * GetTail() {
            return tail_;
        }
    private:
        Dnode<T> *head_;
        Dnode<T> *tail_;
};


#endif
