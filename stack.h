#ifndef STACK
#define STACK
#include <QDebug>
#define MAX 10000
template <class T>
class Stack
{
private:
    int count;
    T data[MAX];
public:
    Stack()
    {
        count = 0;
    }

    bool is_empty() const
    {
        return count == 0;
    }

    bool is_full() const
    {
        return count == MAX;
    }

    int size()
    {
        return count;
    }

    void push(T item)
    {
        if (this->is_full())
        {
            qDebug("Stack is full!");
        }
        data[count] = item;
        count++;
        return;
    }

    void pop()
    {
        if (this->is_empty())
        {
            qDebug("Stack is empty!");
        }
        count--;
        return;
    }

    T top()
    {
        if (!this->is_empty())
            return data[count - 1];
        else
        {
            qDebug("Stack is empty!");
        }
    }

    void Stack::clear()
    {
        count = 0;
    }
};
#endif // STACK

