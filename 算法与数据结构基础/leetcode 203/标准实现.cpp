

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
    ListNode *removeElements(ListNode *head, int val)
    {
        // �ӿ�ʼ���־���Ҫɾ����Ԫ��
        while (head != nullptr && head->val == val)
        {
            // ��ͷ��㸳ֵ��Ҫɾ���Ľڵ�
            ListNode *delNode = head;
            // ͷ���ָ����һ�����
            head = head->next;
            delete delNode;
        }
        // ȫ������Ҫɾ����Ԫ��
        if (head == nullptr)
            return nullptr;

        // Ҫɾ����Ԫ�����м�
        // ����һ��ͷָ��
        ListNode *pre = head;
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
        return head;
    }
};