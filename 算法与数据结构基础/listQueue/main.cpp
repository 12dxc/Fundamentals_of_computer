#include <iostream>
using namespace std;
#include "LinkedListQueue.h"

int main()
{
    // ��������
    LinkedListQueue<int> queue;
    // ���
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(i);
        cout << queue << endl;
        // ����
        if (i % 3 == 2) // ÿ���ε���һ��Ԫ��
        {
            queue.dequeue();
        }
    }

    system("pause");
    return 0;
}