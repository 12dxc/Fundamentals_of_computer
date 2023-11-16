#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 10   // ����Ԫ�ص�������
#define ElemType int // ���е�Ԫ������

// ˳��洢ʵ�ֶ��еĽṹ
typedef struct SqQeque
{
    ElemType data[MaxSize]; // �þ�̬�����Ŷ���Ԫ��
    int front, end;         // ��ͷָ��Ͷ�βָ��(���ж�βָ��ָ����Ƕ�βԪ�ص���һ��λ��)
} SqQeque;

// ��ʼ������
bool InitQueue(SqQeque *Q)
{
    // ��ʼ��ʱ��ͷ����βָ��ָ��0
    Q->front = 0;
    Q->end = 0;
}
// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQeque Q)
{
    // ��ͷ�Ͷ�βָ��ͬһ��Ԫ��˵���ӿ�
    if (Q.end = Q.front)
        return true;
    else
        return false;
}
// ���
bool EnQueue(SqQeque *Q, ElemType x)
{
    // ��β����һ��ָ���Ƕ�ͷ˵����β����
    if ((Q->end + 1) % MaxSize == Q->front)
        return false;
    Q->data[Q->end] = x;              // ��x�����β
    Q->end += (Q->end + 1) % MaxSize; // ��βָ�����
    return true;
}
// ����
ElemType DeQueue(SqQeque *Q)
{
    if ((Q->end + 1) % MaxSize == Q->front)
        return -1;
    ElemType x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return x;
}
// ��ȡ��ͷԪ�أ�������
ElemType GetHead(SqQeque Q)
{
    if (Q.end == Q.front)
        return -1;
    ElemType x = Q.data[Q.front];
    return x;
}

int main()
{
    SqQeque q;
    InitQueue(&q);
    // Ϊ�������0~9��Ԫ��
    for (int i = MaxSize; i != 0; --i)
    {
        EnQueue(&q, i);
    }
    // �鿴��ͷ
    printf("��Ӻ�Ķ���: %d\n", GetHead(q));
    // ����
    DeQueue(&q);
    printf("���Ӻ�Ķ���: %d\n", GetHead(q));

    if (QueueEmpty(q))
        printf("����Ϊ��");

    system("pause");
    return 0;
}