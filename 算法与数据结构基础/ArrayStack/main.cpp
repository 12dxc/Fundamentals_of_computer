#include <iostream>
using namespace std;
#include "ArrayStack.h"

int main()
{

    ArrayStack<int> stack;
    // ��ջ
    for (int i = 10; i > 0; i--)
    {
        stack.push(i);
    }
    cout << "��ջ��" << endl
         << stack << endl;

    // ��ջ
    stack.pop();
    cout << "��ջ��" << endl
         << stack << endl;

    // �鿴ջ��Ԫ��
    cout << "ջ��Ԫ��Ϊ��" << stack.peek() << endl;

    // ����ջ�Ƿ�Ϊ�գ���Ϊ�մ�ӡջ�Ĵ�С������
    if (!stack.isEmpty())
    {
        cout << "ջ��С��" << stack.size() << " ջ������" << stack.capacity() << endl;
    }

    system("pause");
    return 0;
}