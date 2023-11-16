#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 // Ĭ�ϵ���󳤶�

// ����һ����̬���Ա�
typedef struct
{
    int *data;   // ָʾ��̬���������ָ��
    int MaxSize; // ˳�����������
    int length;  // ˳���ĵ�ǰ����
} SeqList;       // ˳�������Ͷ��壨��̬���䷽ʽ��

// ��������������ʼ��һ��˳���
void InitList(SeqList *L)
{
    // ��malloc��������һƬ�����Ĵ洢�ռ�
    L->data = (int *)malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

// ���Ӷ�̬���鳤��
void IncreaseSize(SeqList *L, int len)
{
    int *p = L->data;                                          // ��ʱָ��ָ��ԭ�����Ա�
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int)); // ���·������ռ�
    for (int i = 0; i != L->length; ++i)
    {
        L->data[i] = p[i]; // �����ݸ��Ƶ�������
    }
    L->MaxSize = L->MaxSize + len; // ˳�����󳤶����� len
    free(p);                       // �ͷ�ԭ���ڴ�ռ�
}

int main()
{
    SeqList L;    // ����һ��˳���
    InitList(&L); // ��ʼ��˳���

    IncreaseSize(&L, 5);

    return 0;
}