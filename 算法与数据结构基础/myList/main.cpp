#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList<int> linkedList;
    // �������������Ԫ��
    for (int i = 0; i < 5; i++)
    {
        linkedList.addFrist(i);
        cout << linkedList << endl;
    }

    linkedList.add(2, 666);
    cout << linkedList << endl;

    cout << "ɾ������:" << endl;
    linkedList.remove(2);
    cout << linkedList << endl;
    linkedList.removeFirst();
    cout << linkedList << endl;
    linkedList.removeLast();
    cout << linkedList << endl;

    system("pause");
    return 0;
}