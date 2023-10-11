#include <iostream>
using namespace std;
#include "Queue.h"

template <class T>
class LinkedListQueue : public Queue<T>
{
private:
    struct Node
    {
        T e;
        Node *next;

        friend ostream &operator<<(ostream &os, const Node &node)
        {
            os << node.e;

            return os;
        }

        Node(T e, Node *next)
        {
            this->e = e;
            this->next = next;
        }

        Node(T e) : Node(e, nullptr) {}

        Node()
        {
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;
    int m_size;

    friend ostream &operator<<(ostream &os, const LinkedListQueue &list)
    {
        os << "Queue: front ";

        // ���Ƶ������ı���
        for (Node *cur = list.head->next; cur != nullptr; cur = cur->next)
        {
            cout << (*cur) << "->";
        }
        os << "NULL tail";
        return os;
    }

public:
    LinkedListQueue()
    {
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
    ~LinkedListQueue()
    {
        if (head)
        {
            Node *toDel = head;
            head = head->next;
            delete toDel;
        }
    }

    int size() override
    {
        return m_size;
    }
    bool isEmpty() override
    {
        return m_size == 0;
    }
    // ���  ������β����
    void enqueue(T e)
    {
        // ����û��Ԫ��
        if (tail == nullptr)
        {
            tail = new Node(e);
            head = tail;
        }
        // ������Ԫ��
        else
        {
            // βָ�����һ����㴴����Ԫ��
            tail->next = new Node(e);
            // βָ��ָ��ǰβ������һ��Ԫ��
            tail = tail->next;
        }
        m_size++;
    }
    // ����
    T dequeue()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("���ܴӿն������˳�����");
        }
        T ret = head->e;
        // ����һ����ʱ����ָ��ͷ���
        Node *retNode = head;
        // ͷ���ָ����һ��Ԫ��
        head = head->next;
        delete retNode;

        // ������Ӻ󣬶���Ϊ��
        if (head == nullptr)
        {
            tail = nullptr;
        }
        m_size--;
        return ret;
    }
    T getFront()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("���ܴӿն����з��ض���Ԫ��");
        }
        return head->e;
    }
};
