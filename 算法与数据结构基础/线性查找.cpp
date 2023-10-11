#include <iostream>
#include <vector>
using namespace std;

class Linear_search
{
public:
    // ����������ֱ�ӵ��ã���Ҫ��static
    static auto search(vector<int> &v, int target)
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

    auto res = Linear_search::search(v, 12);
    cout << "���ҵ�ֵ�±�Ϊ��" << res << endl;

    res = Linear_search::search(v, 54);
    cout << "���ҵ�ֵ�±�Ϊ��" << res << endl;

    system("pause");
    return 0;
}