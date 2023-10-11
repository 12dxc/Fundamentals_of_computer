#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class InsertSort
{
public:
    // ����������
    // �Դ��������v��������
    static void sort(vector<T> &v)
    {
        // ���forѭ��:����������ÿ��Ԫ��
        for (int i = 0; i < v.size(); i++)
        {
            T temp = v[i];
            int j;
            for (j = i; i - 1 >= 0 && temp < v[j - 1]; j--)
            {
                v[j] = v[j - 1];
            }
            v[j] = temp;
        }
    }

    // ��ӡ����
    // ��ӡ��������������
    static void myPrint(vector<T> &v)
    {
        // ʹ�õ�������������
        for (auto it = v.begin(); it != v.end(); it++)
        {
            // �����ǰԪ��
            cout << *it << " ";
        }
        // ��ӡ����
        cout << endl;
    }
    // ��������
    static void addArr(vector<T> &v, int len)
    {
        for (int i = 0; i < len; i++)
        {

            int r = rand() % 100; // ���������
            v.push_back(r);
        }
    }
};

int main()
{
    srand((unsigned)time(NULL));

    // ����������������ʼ��
    vector<int> v;
    InsertSort<int>::addArr(v, 10);

    // ���ò��������㷨��������������
    InsertSort<int>::sort(v);

    // ���ô�ӡ�����������������
    InsertSort<int>::myPrint(v);

    system("pause");
    return 0;
}