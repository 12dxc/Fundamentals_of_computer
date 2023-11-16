#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ���嵥����������
typedef struct LNode
{
    int data;           // ÿ���ڵ���һ������Ԫ��
    struct LNode *next; // ָ��ָ����һ�ڵ�
} LNode, *LinkList;

// ��ʼ��һ���յĵ�������ͷ��㣩
bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode)); // ����һ��ͷ���
    if (*L == NULL)
        return false;  // �ڴ治�㣬����ʧ��
    (*L)->next = NULL; // ͷ�ڵ�֮���ÿ�
    return true;
}

// �ж������Ƿ�Ϊ��
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

// ��������룬�ı�ǰһ�����ָ���Ҫ�������ָ���ָ�򼴿�
bool ListInsert(LinkList L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;                      // ָ��pָ��ǰɨ��Ľ��
    int j = 0;                     // ��ǰpָ����ǵڼ������
    p = L;                         // Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while (p != NULL && j < i - 1) // ѭ���ҵ���i-1����㣬������λ��ǰһ�����
    {
        p = p->next;
        ++j;
    }
    if (p == NULL) // iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;       // �·���Ľ�㣬��ֵ��������ֵ
    s->next = p->next; // ��ָ�����һ�����ָ��i-1��������һ�����
    p->next = s;       // �����s���뵽p֮�󣬼��ı�i-1����ָ��
    return true;       // ����ɹ�
}

bool ListDelete(LinkList L, int i)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    // Ѱ��Ҫɾ��Ԫ�ص�ǰһ��
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL || p->next == NULL) // iֵ���Ϸ�����ɾ��λ��Ϊ��
        return false;
    // q��ֵΪp����һ��Ԫ�أ���Ҫɾ��Ԫ��
    LNode *q = p->next;
    // p����һ��Ԫ��ָ��Ҫɾ��Ԫ�ص���һ��
    p->next = q->next;
    free(q);
    return true;
}

// ��λ����
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 1;
    p = L;
    // Ѱ��Ҫɾ��Ԫ�ص�ǰһ��
    while (p != NULL && j < i)
    {
        p = p->next;
        ++j;
    }

    return p;
}

// ��ֵ����
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

int main()
{
    LinkList L; // ����һ��ָ�������ָ��
    InitList(&L);
    // ͷ��㲻��Ԫ�أ����Դ�1��ʼ
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    printf("����Ԫ�غ�:\n");
    for (LNode *p = L->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");

    printf("ɾ��Ԫ�غ�:\n");
    ListDelete(L, 1);
    for (LNode *p = L->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");

    printf("��������1Ϊ: %d\n", LocateElem(L, 20)->data);

    return 0;
}