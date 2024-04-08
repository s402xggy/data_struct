#ifndef _STACK_HPP__
#define _STACK_HPP__

const int kSTACK_SIZE = 256;

template <class T>
class Stack{
    public:
        Stack(int size);
        Stack(const Stack & other);
        Stack& operator=(const Stack &other);
        Stack(Stack && other) noexcept;
        Stack & operator=(Stack && other) noexcept;

        ~Stack();
        void Push(T d);
        T Pop();
        bool IsEmpty();
        

    private:
        T *data_;
        int size_;
        int top_;
};









#endif
