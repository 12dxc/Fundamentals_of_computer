struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // ����һ������ͷ���
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // ����һ��ͷָ��
        ListNode *pre = dummyHead;
        // ������������
        while (pre->next != nullptr)
        {
            // �Ա�������ÿ��Ԫ��
            if (pre->next->val == val)
            {
                // ����һ����ʱ���ָ��ͷ������һ�����
                ListNode *delNode = pre->next;
                // ͷ���ָ������һ�����
                pre->next = delNode->next;
                // �ͷ���ʱ���
                delete delNode;
            }
            // �������Ҫ�ҵ�Ԫ�أ�ʹ������ָ����һ��Ԫ�ؼ�������
            else
            {
                pre = pre->next;
            }
        }
        return dummyHead->next;
    }
};