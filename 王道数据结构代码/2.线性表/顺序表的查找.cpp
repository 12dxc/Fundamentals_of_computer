#include <cstdio>
#include <cstdlib>
#include <iostream>
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

// ���Ա�������
bool ListInsert(SqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1) // �ж�i�ķ�Χ�Ƿ���Ч
        return false;
    if (L->length >= MaxSize) // ��ǰ�洢�ռ���������ֹ����
        return false;

    for (int j = L->length; j >= i; j--) // ����i��Ԫ�ؼ�֮���Ԫ�غ���
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e; // ��λ��index����elem
    L->length++;        // ���ȼ�1
    return true;
}

// ���Ա�ɾ������
bool ListDelete(SqList *L, int i, int &e)
{
    if (i < 1 || i > L->length) // �ж�i�ķ�Χ�Ƿ���Ч
        return false;
    e = L->data[i - 1];                 // ����ɾ����Ԫ�ظ�ֵ��e
    for (int j = i; i < L->length; j++) // ����i��λ�ú��Ԫ��ǰ��
        L->data[j - 1] = L->data[j];
    L->length--; // ���Ա��ȼ�1
    return true;
}

// ��λ����
int GetElem(SqList L, int i)
{
    return L.data[i];
}
// ��ֵ����
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] == e)
            return i;
        else
            return -1;
    }
}

int main()
{
    SqList L;     // ����һ��˳���
    InitList(&L); // ��ʼ��˳���
    int e = -1;

    ListInsert(&L, 1, 100);
    ListDelete(&L, 1, e);
    for (int i = 0; i != L.length; ++i)
    {
        printf("%d ", L.data[i]);
    }
    std::cout << GetElem(L, 0) << " " << LocateElem(L, 100) << std::endl;

    return 0;
}