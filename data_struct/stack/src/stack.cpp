#include "stack.hpp"


template <class T>
Stack<T>::Stack(int size):size_(size) {
    data_ = new T[size_];
    top_ = 0;
}

template <class T>
Stack<T>::Stack(const Stack &other):size_(other.size_), top_(other.top_) {
    data_ = new T[size_];   
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack &other) {
    if (this != &other) {
        delete []data_;
        size_ = other.size_;
        top_ = other.top_;
        data_ = new T[size_];
        for (int i = 0; i <= size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}



template <class T>
Stack<T>::~Stack() {
    delete []data_;
}

template <class T>
void Stack<T>::Push(T d) {
    data_[top_] = d;
    top_ ++;
}

template <class T>
T Stack<T>::Pop() {
    return data_[--top_];
}


template <class T>
bool Stack<T>::IsEmpty() {
    return top_ == 0;
}


template <class T>
Stack<T>::Stack(Stack && other) noexcept: data_(other.data_),size_(other.size_), top_(other.top_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.top_ = -1;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack && other) noexcept {
    if (this != &other) {
        delete data_;

        data_ = other.data_;
        size_ = other.size_;
        top_ = other.top_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.top_ = -1;
    }
    return *this;
}
