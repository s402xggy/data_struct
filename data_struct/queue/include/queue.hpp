#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

/*
    队列： fifo， 需要有一个头head和一个尾tail
    1)空队列： head == tail
    为了避免假溢出： 需要使用循环队列。假溢出：当队列tail到达数据数组的末尾时， 并
                  不一定是队列满了，因为出队列后，数据数组前面的位置会是空的。
    2)队列满： tail + 1 == head

    思想：一个不大于max的数与max取余，仍然是他本身。

*/


template<class T>
class Queue{
    public: 
        Queue(int size):size_(size) {
            data_ = new T[size_];
            head_ = tail_ = 0;
        }
        Queue(const Queue & queue):head_(queue.head_), tail_(queue.tail_),size_(queue.size_) {
            delete []data_;
            data_ = new T[size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = queue.data_[i];
            }
        }
        Queue&  operator=(const Queue &queue) {
            if (this == &queue)
                return *this;
            else {
                size_ = queue.size_;
                head_ = queue.head_;
                tail_ = queue.tail_;
                delete []data_;
                data_ = new T[size_];
                for (int i = 0; i < size_; i++) {
                    data_[i] = queue.data_[i];
                }
            }
            return *this;            
        }

        Queue(Queue && queue) noexcept : size_(queue.size_), head_(queue.head_), tail_(queue.tail_), data_(queue.data_) {
            queue.size_ = -1;
            queue.data_ = nullptr;
            queue.head_ = queue.tail_ = 0;
        }

        Queue & operator=(Queue && queue) noexcept{
            if (this == &queue)
                return *this;
            else {
                size_ = queue.size_;
                head_ = queue.head_;
                tail_ = queue.tail_;
                data_ = queue.data_;
                queue.data_ = nullptr;
                queue.size_ = -1;
                queue.head_ = queue.tail_ = 0;
            }
        }

        ~Queue() {
            delete []data_;
        }



    public:
        void Enqueue(T d) {
            data_[tail_] = d;
            tail_ = (tail_ + 1) % size_;
        }

        T Dequeue(void) {
            T d = data_[head_];
            head_ = (head_ + 1) % size_;
            return d; 
        }

        bool IsEmpty() {
            return head_ == tail_;
        }

        bool IsFull() {
            return (tail_ + 1) % size_ == head_;
        }



    private:
        int head_;
        int tail_;
        int size_;
        T *data_;
};


#endif
