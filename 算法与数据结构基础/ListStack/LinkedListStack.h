#include "Stack.h"
#include "LinkedList.h"

template <class T>
class LinkedListStack : public Stack<T>
{
private:
    LinkedList<T> list;
    friend ostream &operator<<(ostream &os, const LinkedListStack<T> &lsitStack)
    {
        // ʹ�����ʽΪԭ����������ʽ
        os << "Stack: top " << lsitStack.list;
        return os;
    }

public:
    LinkedListStack()
    {
    }
    // ����ջ��С
    int size() override
    {
        return list.size();
    }
    // �鿴ջ�Ƿ�Ϊ��
    bool isEmpty() override
    {
        return list.isEmpty();
    }
    // ѹջ
    void push(T e) override
    {
        list.addFrist(e);
    }
    // ��ջ
    T pop() override
    {
        return list.removeFirst();
    }
    // �鿴ջ��
    T peek() override
    {
        return list.getFrist();
    }
};
