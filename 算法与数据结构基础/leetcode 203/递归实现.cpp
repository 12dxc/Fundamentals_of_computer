#include <iostream>
using namespace std;

// ������
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
            throw invalid_argument("���鲻��Ϊ��");
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
        // 1�����head���Ϊ�գ�ֱ�ӷ��ؿ�
        if (head == nullptr)
        {
            return nullptr;
        }
        // 2���ݹ����removeElementsȥ����head->next��ʼ��������,ɾ��ֵΪval�Ľڵ�
        ListNode *res = removeElements(head->next, val);
        // 3�����head�ڵ��ֵ����val,˵����Ҫɾ��ͷ�ڵ�,����ֱ�ӷ��صݹ麯���Ľ��res,Ҳ����ȥ��ͷ�ڵ���������
        if (head->val == val)
        {
            return res;
        }
        // ���head�ڵ��ֵ������val,˵��ͷ�ڵ㱣��,��ô�Ͱ�ͷ�ڵ�head��ݹ麯���Ľ��res��������,Ȼ�󷵻����������ͷ�ڵ������
        else
        {
            head->next = res;
            return head;
        }
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