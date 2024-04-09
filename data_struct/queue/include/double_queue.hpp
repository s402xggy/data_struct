#ifndef __DOUBLE_QUEUE_HPP__
#define __DOUBLE_QUEUE_HPP__

/*
    双端队列： 头和尾都可以出队列，入队列
    head端出队列：  head = (head + 1) % size; 
    head端入队列：  head = (head - 1 + size) % size;
    tail段出队列：  tail = (tail - 1 + size) % size;
    tail端入队列：  tail = (tail + 1) % size;
    队列是否为空： head == tail
    队列是否为满： （tail + 1） % size == head;
*/

template <class T> 
class Dqueue{
    public:
        Dqueue(int size):size_(size) {
            head_ = tail_ = 0;
            data_ = new T[size_];
        }
        ~Dqueue() {
            delete []data_;
        }

        void TailEnqueue(const T &d) {
            data_[tail_] = d;
            tail_ = (tail_ + 1) % size_;
        }

        T TailDequeue() {
            tail_ = (tail_ - 1 + size_) % size_;
            return data_[tail_];
        }

        void HeadEnqueue(const T &d) {
            head_ = (head_ - 1 + size_) % size_;
            data_[head_] = d;
        }

        T HeadDequeue() {
            T temp = data_[head_];
            head_ = (head_ + 1) % size_;
            return temp;
        }

        bool IsEmpty() {
            return head_ == tail_;
        }

        bool IsFull() {
            return ((tail_ + 1) % size_) == head_;
        }


    private:
        int head_;
        int tail_;
        int size_;
        T *data_;
};

#endif
