#include <iostream>
using namespace std;
#include "LoopQueue.h"

// ��������
int main()
{
    // ��������
    LoopQueue<int> queue;
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