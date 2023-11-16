#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10   // ��̬������󳤶�
#define ElemType int // ջ��Ԫ������

typedef struct
{
    ElemType data[MaxSize];
    int top; // ����ջ��ָ��
} Stack;
// ��ʼ��ջ
void InitStack(Stack *s)
{
    s->top = -1;
    for (int i = 0; i != MaxSize; ++i)
    {
        s->data[i] = 0;
    }
}
// ����ջ
void DestroyStack(Stack *s)
{
    s->top = -1;
}
// ��ջ
bool Push(Stack *s, ElemType x)
{
    if (s->top == MaxSize - 1) // ջ��
        return false;
    ++s->top;
    s->data[s->top] = x;
    return true;
}
// ��ջ
bool Pop(Stack *s)
{
    if (s->top == -1) // ջΪ��
        return false;
    s->data[s->top] = 0; // ջ��Ԫ���ȳ�ջ
    s->top--;            // ָ���ټ�1
    return true;
}
// �鿴ջ��Ԫ��
ElemType GetTop(Stack s)
{
    if (s.top == -1) // ջΪ��
        return -1;
    return s.data[s.top];
}

// �ж��Ƿ�Ϊ��ջ
bool StackEmpty(Stack s)
{
    if (s.top == -1) // ջΪ��
        return true;
    else
        return false;
}

int main()
{
    Stack s;       // ����ջ
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

    if (StackEmpty(s))
        printf("ջΪ�գ�");

    return 0;
}