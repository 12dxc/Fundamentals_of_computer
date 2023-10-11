#include <iostream>
using namespace std;

template <class T>
class Array
{
    friend ostream &operator<<(ostream &os, const Array<T> &array)
    {
        os << "Array: size = " << array.m_size << " , capacity = " << array.m_capacity << endl;
        os << "[";
        for (int i = 0; i < array.m_size; i++)
        {
            os << array.m_data[i];
            if (i != array.m_size - 1)
            {
                os << ", ";
            }
        }
        os << "]";

        return os;
    }

public:
    // ���캯�����������������capacity����Array
    Array(int capacity = 10) : m_capacity(capacity) // ��������Σ�ΪĬ�Ϲ��촴������10������
    {
        m_data = new T[capacity];
        m_size = 0;
    };
    ~Array()
    {
        // �ͷŶ��ڴ�ռ�
        delete[] m_data;
    }
    // ��ȡ������Ԫ�صĸ���
    int size() const
    {
        return m_size;
    }
    // ��ȡ���������
    int capacity() const
    {
        return m_capacity;
    }
    // ��ȡ�Ƿ�Ϊ��
    bool isEmpty() const
    {
        return m_size == 0;
    }
    // ������Ԫ�غ����һ����Ԫ��
    void addLast(T e)
    {
        add(m_size, e);
    }
    // ���һ��Ԫ�����λ��
    void addFrist(T e)
    {
        add(0, e);
    }
    // �ڵ�index��λ�ò���һ����Ԫ��
    void add(int index, T e)
    {
        // �������������������� �׳��쳣
        if (index < 0 || index > m_size)
        {
            throw invalid_argument("���ʧ��!Ҫ��index >= 0��index <= size");
        }
        // ��� �׳��쳣
        if (m_size == m_capacity)
        {
            resize(1.5 * m_capacity);
        }

        for (int i = m_size - 1; i >= index; i--)
        {
            // ����һ��Ԫ�ظ���ǰһ��Ԫ��
            m_data[i + 1] = m_data[i];
        }
        m_data[index] = e;
        m_size++;
    }
    // ��ȡindex����λ�õ�Ԫ��
    T get(int index) const
    {
        // �������������������� �׳��쳣
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("���ʧ��!Ҫ��index >= 0��index <= size");
        }
        return m_data[index];
    }
    // �޸�index����λ�õ�Ԫ��
    void set(int index, T e)
    {
        m_data[index] = e;
    }
    // �����������Ƿ���Ԫ��
    bool contains(T e)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (m_data[i] == e)
            {
                return true;
            }
        }
        return false;
    }
    // ����������Ԫ�����ڵ���������������ڷ���-1
    int find(T e)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (m_data[i] == e)
            {
                return i;
            }
        }
        return -1;
    }
    // ɾ��������ָ����Ԫ��
    T remove(int index)
    {
        if (index < 0 || index >= m_size)
        {
            throw invalid_argument("���ʧ��!Ҫ��index >= 0��index <= size");
        }
        T ret = m_data[index];
        for (int i = index + 1; i < m_size; i++)
        {
            m_data[i - 1] = m_data[i];
        };
        m_size--;

        // Ϊ���Է������𵴣���Ԫ�ظ���С��������1/3���ٽ�������
        if (m_size == m_capacity / 3 && m_capacity / 2 == 0)
        {
            resize(m_capacity / 1.5);
        }
        return ret;
    }
    // ��������ɾ��Ԫ��e
    T removeElement(T e)
    {
        int index = find(e);
        if (index != -1)
        {
            remove(index);
        }
    }

private:
    // ����ָ��
    T *m_data;
    // �����С
    int m_size;
    // ��������
    int m_capacity;

    // ʹ����������̬�仯
    void resize(int newCapacity)
    {
        // ����һ�������飬���������ڴ���������������
        T *newData = new T[newCapacity];
        // ����ԭ�������飬��ԭ����Ԫ�ظ�ֵ��������
        for (int i = 0; i < m_size; i++)
        {
            newData[i] = m_data[i];
        }
        // ������ָ���Ϊ������
        m_data = newData;
        // ͬ��������
        m_capacity = newCapacity;
    }
};
