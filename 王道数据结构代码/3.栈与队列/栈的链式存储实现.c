#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10   // ��̬������󳤶�
#define ElemType int // ջ��Ԫ������

// ��ջ�ṹ
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
// ����ṹ
typedef struct
{
    LinkStackPtr top;
    int count; // ������
} LinkStack;

// ��ʼ��һ���յĵ�����ջ����ͷ��㣩
bool InitStack(LinkStack *s)
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode)); // ����һ��ͷ���
    if (!s->top)
        return false; // �ڴ治�㣬����ʧ��
    s->top = NULL;    // ͷ���nextָ���ÿ�
    s->count = 0;     // ������0
    return true;
}
// �ж��Ƿ�Ϊ��ջ
bool StackEmpty(LinkStack s)
{
    if (s.count == 0) // ջΪ��
        return true;
    else
        return false;
}
// ����ջ
void ClearStack(LinkStack *s)
{
    LinkStackPtr p, q;
    p = s->top;
    while (p)
    {
        q = p;       // ���浱ǰͷ���
        p = p->next; // ����ͷ���ָ��;
        free(q);     // �ͷŵ�ǰͷ���
    }
    s->count = 0;
}
// ��ջ
bool Push(LinkStack *s, ElemType e)
{
    LinkStackPtr newTop = (LinkStackPtr)malloc(sizeof(StackNode));
    newTop->data = e;      // �½�㸳ֵ
    newTop->next = s->top; // �½����¸����ָ��ͷ���
    s->top = newTop;       // ͷ���ָ�򣨸�Ϊ���½��
    s->count++;            // ����+1
    return true;
}
// ��ջ
ElemType Pop(LinkStack *s)
{
    if (s->count == 0) // ջΪ��
        return -1;
    int x = s->top->data;
    LinkStackPtr p = s->top; // ����һ��ָ��ָ��Ҫ���ٵĽ��,��ͷ���
    s->top = s->top->next;   // ָ������һλ
    free(p);                 // ���ٽ��
    s->count--;              // ����-1
    return x;
}
// �鿴ջ��Ԫ��
ElemType GetTop(LinkStack s)
{
    if (s.top == 0) // ջΪ��
        return -1;
    return s.top->data;
}

int main()
{
    LinkStack s;   // ����ջ
    InitStack(&s); // ��ʼ��ջ
    // ѹջ��0~9����ջ
    for (int i = 0; i < MaxSize; i++)
    {
        Push(&s, i);
    }
    // �鿴ջ��
    printf("%d\n", GetTop(s)); // 9
    // ��ջ
    Pop(&s);
    printf("%d\n", GetTop(s)); // 8

    printf("����: %d\n", s.count);

    if (StackEmpty(s))
        printf("ջΪ�գ�");

    system("pause");
    return 0;
}