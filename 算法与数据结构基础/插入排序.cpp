#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;

// ģ����,����ʵ�ֲ��������㷨
// ģ�����T��ʾ���Զ��������͵����ݽ�������
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
            // �ڲ�forѭ��:����ǰԪ�ز��뵽��ȷλ��
            for (int j = i; j - 1 >= 0; j--)
            {
                // �����ǰԪ��С��ǰһ��Ԫ��,��������Ԫ��
                if (v[j] < v[j - 1])
                {
                    swap(v[j], v[j - 1]);
                }
                // ����˵���Ѿ��ҵ�����ȷλ��,�˳��ڲ�ѭ��
                else
                {
                    break;
                }
            }
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

            int r = rand(); // ���������
            v.push_back(r);
        }
    }
};

int main()
{
    srand(time(0)); // ��������

    // ����������������ʼ��
    vector<int> v;
    InsertSort<int>::addArr(v, 10000);

    auto begin = chrono::high_resolution_clock::now();

    // ���ò��������㷨��������������
    InsertSort<int>::sort(v);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::seconds>(end - begin);

    printf("%f\n", elapsed.count());

    // ���ô�ӡ�����������������
    // InsertSort<int>::myPrint(v);

    system("pause");
    return 0;
}