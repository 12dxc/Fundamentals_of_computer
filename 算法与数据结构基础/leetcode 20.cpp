#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool test(string str)
{
    stack<char> sta;
    for (int i = 0; i < str.length(); i++)
    {
        // �����ַ��������ַ������ַ�����c
        char c = str.at(i);
        // ������������ջ
        if (c == '{' || c == '[' || c == '(')
        {
            sta.push(c);
        }
        else
        {
            if (sta.empty())
                return false;
            // ��¼ջ��Ԫ��
            char topChar = sta.top();
            sta.pop();
            // �������������,����ջ��Ԫ��ƥ��,������֮��Ե����ţ�ֱ�ӷ���false
            if (c == ')' && topChar != '(' || c == ']' && topChar != '[' || c == '}' && topChar != '{')
            {
                return false;
            }
        }
    }

    // ջ�շ���true
    return sta.empty();
}

int main()
{
    string str("{[()]}");
    cout << test(str);

    system("pause");
    return 0;
}