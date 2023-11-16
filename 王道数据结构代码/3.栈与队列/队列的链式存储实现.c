#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ElemType int // ���е�Ԫ������

// ��ʽ���н��
typedef struct LinkNode
{
    ElemType data; // �þ�̬�����Ŷ���Ԫ��
    struct LinkNode *next;
} LinkNode;
// ��ʽ����
typedef struct
{
    LinkNode *front, *end; // ���еĶ�ͷָ��Ͷ�βָ�루frontָ���ͷ��㣩
    int len;               // ���г���
} LinkQueue;

// ��ʼ�����У���ͷ��㣩
bool InitQueue(LinkQueue *Q)
{
    // ��ʼ��front��end��ָ��ͷ���
    Q->front = Q->end = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
    Q->len = 0;
}
// ��ʼ�����У�����ͷ��㣩
// bool InitQueue(LinkQueue *Q)
// {
//     // ��ʼ��front��end��ָ��NULL
//     Q->front = NULL;
//     Q->end = NULL;
// }

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
    // ��ͷ�Ͷ�βָ��ͬһ��Ԫ��˵���ӿ�
    if (Q.front = Q.end)
        return true;
    else
        return false;
}
// ���
void EnQueue(LinkQueue *Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkQueue));
    s->data = x;
    s->next = NULL;   // �¼���Ľ������β��������nextָ��Ҫָ���
    Q->end->next = s; // �½����뵽end֮��
    Q->end = s;       // �޸ı�βָ��
    Q->len++;
}
// ����
ElemType DeQueue(LinkQueue *Q)
{
    if (Q->front == Q->end)
        return -1;                // �ն�
    LinkNode *p = Q->front->next; // ����ָ��p����Ҫɾ���Ľ�㣬����ͷ������һ�����
    ElemType x = p->data;         // �ñ���x�����ͷԪ�ص�ֵ�����ڷ���
    Q->front->next = p->next;     // �޸�ͷ����nextָ�룬��ָ������һλ

    if (Q->end == p)       // �˴������һ��������
        Q->end = Q->front; // �޸�endָ��

    free(p); // �ͷŽ��ռ�
    Q->len--;
    return x;
}
// ��ȡ��ͷԪ�أ�������
ElemType GetHead(LinkQueue Q)
{
    if (Q.front == Q.end)
        return -1;
    ElemType x = Q.front->next->data; // frontָ��Ŀ�ͷ��㣬���Զ�ͷԪ��Ϊ��һ������
    return x;
}
// ��ȡ�ӳ�
int QueueLength(LinkQueue Q)
{
    return Q.len;
}

int main()
{
    LinkQueue q;
    InitQueue(&q);
    // Ϊ�������0~9��Ԫ��
    for (int i = 9; i != -1; --i)
    {
        EnQueue(&q, i);
    }
    // �鿴��ͷ
    printf("��Ӻ�Ķ���: %d\n", GetHead(q));
    // ����
    DeQueue(&q);
    printf("���Ӻ�Ķ���: %d\n", GetHead(q));

    if (IsEmpty(q))
        printf("����Ϊ��");

    printf("���ڶ��г���: %d\n", QueueLength(q));

    system("pause");
    return 0;
}