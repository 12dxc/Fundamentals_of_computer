#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // ������󳤶�

// ����һ����̬���Ա�
typedef struct
{
    int data[MaxSize]; // �þ�̬�ġ����顱�������Ԫ��
    int length;        // ˳���ĵ�ǰ����
} SqList;              // ˳�������Ͷ���

// ��������������ʼ��һ��˳���
void InitList(SqList *L)
{
    for (int i = 0; i != MaxSize; ++i)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

int main()
{
    SqList L;     // ����һ��˳���
    InitList(&L); // ��ʼ��˳���

    return 0;
}