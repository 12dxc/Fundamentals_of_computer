#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    // ����ڵ�Ĺ��캯��
    // ʹ��arrΪ����������һ��������ǰ��ListNodeΪ����ͷ���
    ListNode(int arr[], int len)
    {
        if (arr == NULL || len == 0)
        {
            throw invalid_argument("arr can not be empty");
        }
        this->val = arr[0];
        ListNode *cur = this;
        for (int i = 0; i < len; i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }

    // �Ե�ǰ�ڵ�Ϊͷ����������Ϣ�ַ���
    friend ostream &operator<<(ostream &os, ListNode &list)
    {
        ListNode *cur = &list;
        while (cur)
        {
            os << cur->val << "->";
            cur = cur->next;
        }
        os << "NULL";

        return os;
    }
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        while (pre->next != NULL)
        {
            if (pre->next->val == val)
            {
                ListNode *toDel = pre->next;
                pre->next = toDel->next;
                delete toDel;
            }
            else
            {
                pre = pre->next;
            }
        }

        ListNode *ret = dummyHead->next;
        delete dummyHead;

        return ret;
    }
};

int main()
{

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = new ListNode(arr, len);
    cout << (*head) << endl;

    // ����
    ListNode *ret = Solution().removeElements(head, 6);
    cout << (*ret) << endl;
}