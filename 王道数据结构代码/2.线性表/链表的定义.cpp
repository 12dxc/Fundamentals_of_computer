#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ���嵥����������
typedef struct
{
    int data;    // ÿ���ڵ���һ������Ԫ��
    LNode *next; // ָ��ָ����һ�ڵ�
} LNode, *LinkList;

// ��ʼ��һ���յĵ�������ͷ��㣩
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // ����һ��ͷ���
    if (L == NULL)
        return false; // �ڴ治�㣬����ʧ��
    L->next = NULL;
}

// �ж������Ƿ�Ϊ��
bool Empty(LinkList L)
{
    if (L == NULL)
        return true;
    else
        return false;
}

int main()
{
    LinkList L; // ����һ��ָ�������ָ��
    InitList(&L);

    return 0;
}