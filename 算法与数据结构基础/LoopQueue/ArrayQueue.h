#include "Queue.h"
#include "Array.h"

template <class T>
class ArrayQueue : public Queue<T>
{
private:
    Array<T> array;

    friend ostream &operator<<(ostream &os, const ArrayQueue<T> &queue)
    {
        os << "Queue: front [";

        for (int i = 0; i < queue.array.size(); i++)
        {
            os << queue.array.get(i);
            if (i != queue.array.size() - 1)
            {
                os << ", ";
            }
        }

        os << "] tail";

        return os;
    }

public:
    ArrayQueue(int capacity = 10) : array(capacity)
    {
    }
    // ���ض��д�С
    int size() override
    {
        return array.size();
    }
    // ���ض�������
    int capacity() override
    {
        return array.capacity();
    }
    // ���ض����Ƿ�Ϊ��
    bool isEmpty() override
    {
        return array.isEmpty();
    }
    // ���
    void enqueue(T e) override
    {
        array.addLast(e);
    }
    // ����
    T dequeue() override
    {
        return array.remove(0);
    }
    // �鿴����Ԫ��
    T getFront() override
    {
        return array.get(0);
    }
};