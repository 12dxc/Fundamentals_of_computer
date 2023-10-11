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
        // base case,ͷ�ڵ����һ���ڵ�Ϊ��ʱֱ�ӷ���
        if (head == nullptr || head->next == nullptr)
            return head;

        // �ݹ鷴ת��head->nextΪͷ�ڵ��������
        // �õ���ת���������,����Ϊrev
        ListNode *rev = reverseList(head->next);

        // ��ԭhead�ڵ�ӵ�rev����β��
        // head->nextΪԭtail�ڵ�,����nextָ��head
        head->next->next = head;

        // ��head�ڵ��nextָ���ÿ�,��ֹѭ��
        head->next = nullptr;
        
        // ���ط�ת���������
        return rev;
    }
};