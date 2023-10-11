#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // ��ת����
    ListNode *reverseList(ListNode *head)
    {
        // ����preָ��ָ��null,������Ϊ��ת�����ͷָ��
        ListNode *pre = nullptr;

        // ����curָ��ָ��ԭʼ�����ͷָ��head
        ListNode *cur = head;

        while (cur != nullptr)
        {
            // �洢cur����һ���ڵ�
            ListNode *next = cur->next;
            // �޸�cur��nextָ��ָ��pre,ʵ������ת
            cur->next = pre;
            // pre����ƶ�
            pre = cur;
            // cur����ƶ�
            cur = next;
        }

        // ���ط�ת�������ͷָ��pre
        return pre;
    }
};