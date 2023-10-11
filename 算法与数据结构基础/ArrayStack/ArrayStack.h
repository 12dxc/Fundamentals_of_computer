#include "Array.h"
#include "Stack.h"

template <class T>
class ArrayStack : public Stack<T>
{

private:
    Array<T> array;

    friend ostream &operator<<(ostream &os, const ArrayStack<T> &stack)
    {
        os << "Stack: [";

        for (int i = 0; i < stack.array.size(); i++)
        {
            os << stack.array.get(i);
            if (i != stack.array.size() - 1)
            {
                os << ", ";
            }
        }

        os << "] top";

        return os;
    }

public:
    // ���蹹�캯��Ĭ��ֵ���Բ�����ʵ������
    ArrayStack(int capacity = 10) : array(capacity) {}
    // ��ȡջԪ�ظ���
    int size() override
    {
        return array.size();
    }
    // �鿴ջ�Ƿ�Ϊ��
    bool isEmpty() override
    {
        return array.isEmpty();
    }
    // �鿴ջ����
    int capacity() override
    {
        return array.capacity();
    }
    // ��ջ
    void push(T e) override
    {
        array.addFrist(e);
    }
    // ��ջ
    T pop() override
    {
        return array.remove(0);
    }
    // �鿴ջ��Ԫ��
    T peek() override
    {
        return array.get(0);
    }
};
