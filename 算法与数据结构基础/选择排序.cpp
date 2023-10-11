#include <iostream>
#include <vector>
#include <algorithm> // Ϊ��ʹ��std::swap��std::min_element
using namespace std;

int main()
{

    vector<int> v = {3, 6, 1, 4, 8, 5, 9, 2, 7};

    // ���ѭ��,�����������ѡ������
    for (int i = 0; i < v.size(); i++)
    {

        // �ڲ�ѭ��,�ҳ���i��ĩβ��С��ֵ������
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {

            // ����ҵ���С��ֵ,��¼������
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }

        // ���ҵ�����Сֵ��������ǰλ��i
        swap(v[i], v[minIndex]);
    }

    // ��ӡ����������
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}