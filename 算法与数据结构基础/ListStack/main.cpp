#include <iostream>
using namespace std;
#include "LinkedListStack.h"

int main()
{
    LinkedListStack<int> stack;
    // �������������Ԫ��
    for (int i = 0; i < 5; i++)
    {
        stack.push(i);
        cout << stack << endl;
    }

    stack.push(666);

    cout << "ѹջ��ջ��Ԫ��: " << stack.peek() << endl;

    system("pause");
    return 0;
}