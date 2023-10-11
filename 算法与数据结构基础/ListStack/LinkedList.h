#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // �����
    struct Node
    {
    public:
        // ����Ԫ��
        T e;
        // ָ����һ������Ľڵ�
        Node *next;

        // ��������������������������
        friend ostream &operator<<(ostream &os, const Node &node)
        {
            os << node.e;
            return os;
        }

        // ��ʼ������
        // ���캯����Ԫ�غ�ָ��
        Node(T e, Node *next)
        {
            this->e = e;
            this->next = next;
        }
        // ���캯��ֻ��Ԫ�أ�ָ��Ĭ��Ϊ��
        Node(T e) : Node(e, nullptr) {}
        // ���캯��������
        Node()
        {
            next = nullptr;
        }
    };

    Node *dummyHead;
    int m_size;

    // ����<<��������������������ʽ
    friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
    {
        for (Node *cur = list.dummyHead->next; cur != nullptr; cur = cur->next)
        {
            os << (*cur) << "->";
        }
        os << "NULL";
        return os;
    }

public:
    LinkedList()
    {
        dummyHead = new Node();
        m_size = 0;
    }
    ~LinkedList()
    {
        Node *cur = dummyHead;

        while (cur)
        {
            Node *toDel = cur;
            cur = cur->next;
            delete toDel;
        }
    }
    // ��ȡ�����е�Ԫ�ظ���
    int size()
    {
        return m_size;
    }
    // ��ȡ�����Ƿ�Ϊ��
    bool isEmpty()
    {
        return m_size == 0;
    }

    // �������ĵ�index(0-based)��λ�õ�Ԫ��
    // �������в���һ�����õĲ�������ϰ��: )
    void add(int index, T e)
    {
        // ��������Ϸ���
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("���ʧ�ܣ��Ƿ�������");
        }

        // ���ҵ�����λ�õ�ǰһ���ڵ�
        Node *pre = dummyHead;
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        // �����½ڵ�,ʹ�½ڵ�nextָ��ԭǰһ���ڵ��next

        //  Node node = new Node(e);
        //  node.next = pre->next;
        //  pre->next = node;
        //  �����д��:
        pre->next = new Node(e, pre->next);

        m_size++;
    }
    // ������ͷ����µ�Ԫ��
    void addFrist(T e)
    {
        add(0, e);
    }
    // ������ĩβ����µ�Ԫ��e
    void addLast(T e)
    {
        add(m_size - 1, e);
    }

    // �������ĵ�index(0-based)��λ�õ�Ԫ��
    // �������в���һ�����õĲ�������ϰ��: )
    T get(int index)
    {
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("����ʧ�ܣ��Ƿ�������");
        }
        // 1�����嵱ǰ�ڵ�current����ʼ��Ϊͷ�ڵ�
        Node *cur = dummyHead->next;
        // 2��ʹ��forѭ����ѭ��index�Σ�ÿ�ε�ǰ�ڵ��Ƶ���һ��
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // ����current��Ԫ��ֵ
        return cur->e;
    }
    // ��ȡ����ĵ�һ��Ԫ��
    T getFrist()
    {
        return get(0);
    }
    // ��ȡ��������һ��Ԫ��
    T getLast()
    {
        return get(m_size - 1);
    }

    // �޸�����ĵ�index(0-based)��λ�õ�Ԫ��Ϊe
    // �������в���һ�����õĲ�������ϰ��: )
    void set(int index, T e)
    {
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("�޸�ʧ�ܣ��Ƿ�������");
        }
        Node *cur = dummyHead->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur.e = e;
    }

    // �����������Ƿ���Ԫ��e
    bool contains(T e)
    {
        // 1������һ����ǰ�ڵ�current,��ʼ��Ϊͷ�ڵ�
        Node *cur = dummyHead->next;
        // 2����������,��ǰ�ڵ㲻Ϊ��ʱѭ��ִ��
        while (cur != nullptr)
        {
            // �Ƚϵ�ǰ�ڵ��������Ҫ���ҵ�����
            if (cur->e = e)
            {
                // 3��������,���ص�ǰ�ڵ�
                return true;
            }
            // 4���������,current�ƶ�����һ���ڵ�
            cur = cur->next;
        }
        return false;
    }

    // ��������ɾ��index(0-based)λ�õ�Ԫ��, ����ɾ����Ԫ��
    // �������в���һ�����õĲ�������ϰ��: )
    T remove(int index)
    {
        // 1. ��������Ϸ���
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("ɾ��ʧ��,�Ƿ�������");
        }

        // 2. ��dummyͷ�ڵ㿪ʼ,������indexλ�õ�ǰһ���ڵ�
        Node *prv = dummyHead;
        for (int i = 0; i < index; i++)
        {
            prv = prv->next;
        }

        // 3. ��¼��Ҫɾ���Ľڵ�
        Node *retNode = prv->next;

        // 4. ����Ҫɾ���ڵ��ֵ
        T ret = retNode->e;

        // 5. �޸�ǰһ���ڵ��next,����Ҫɾ���Ľڵ�
        prv->next = retNode->next;

        // 6. ɾ���ڵ�
        delete retNode;

        // 7.��С��1
        m_size--;

        // 8. ����ɾ��ֵ
        return ret;
    }
    // ��������ɾ����һ��Ԫ��, ����ɾ����Ԫ��
    T removeFirst()
    {
        return remove(0);
    }
    // ��������ɾ�����һ��Ԫ��, ����ɾ����Ԫ��
    T removeLast()
    {
        return remove(m_size - 1);
    }
};
