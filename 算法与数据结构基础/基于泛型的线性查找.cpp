#include <iostream>
#include <vector>
using namespace std;

// ʹ�÷��������Բ������������е�����
template <typename T>
class Linear_search
{
public:
    static auto search(vector<T> &v, T target)
    {
        for (auto i = 0; i < v.size(); i++)
        {
            if (v[i] == target)
            {
                // �ҵ�Ŀ�귵���±�
                return i;
            }
        }
        // δ�ҵ�Ŀ�꣬����-1
        return -1;
    }
};

int main()
{
    vector<int> v = {12, 32, 43, 54, 61, 23, 76, 18};

    auto res = Linear_search<int>::search(v, 12);
    cout << "Ҫ���ҵ�ֵ���±�Ϊ��" << res << endl;

    vector<string> vs = {"����", "����", "����", "����"};
    auto resStr = Linear_search<string>::search(vs, "����");
    cout << "Ҫ���ҵ�ֵ���±�Ϊ��" << resStr << endl;

    system("pause");
    return 0;
}