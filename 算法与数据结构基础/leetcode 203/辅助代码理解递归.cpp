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
    ListNode *removeElements(ListNode *head, int val, int depth)
    {
        string depthString = generateDepthString(depth);
        cout << depthString;
        cout << "Call����� " << val << " in " << (*head) << endl;

        // 1�����head���Ϊ�գ�ֱ�ӷ��ؿ�
        if (head == nullptr)
        {
            cout << depthString;
            cout << "����: " << (*head) << endl;
            return head;
        }
        // 2���ݹ����removeElementsȥ����head->next��ʼ��������,ɾ��ֵΪval�Ľڵ�
        ListNode *res = removeElements(head->next, val, depth + 1);
        cout << depthString;
        cout << "����� " << val << ": " << (*res) << endl;
        // 3�����head�ڵ��ֵ����val,˵����Ҫɾ��ͷ�ڵ�,����ֱ�ӷ��صݹ麯���Ľ��res,Ҳ����ȥ��ͷ�ڵ���������

        ListNode *ret;
        if (head->val == val)
        {
            ret = res;
        }
        // ���head�ڵ��ֵ������val,˵��ͷ�ڵ㱣��,��ô�Ͱ�ͷ�ڵ�head��ݹ麯���Ľ��res��������,Ȼ�󷵻����������ͷ�ڵ������
        else
        {
            head->next = res;
            ret = head;
        }

        cout << depthString;
        cout << "����: " << (*rethrow_exception) << endl;
        return ret;
    }

private:
    string generateDepthString(int depth)
    {
        string s;
        for (int i = 0; i < depth; i++)
        {
            s += "--";
        }

        return s;
    }
};

int main()
{

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = new ListNode(arr, len);
    cout << (*head) << endl;

    // ����
    ListNode *ret = Solution().removeElements(head, 6, 0);
    cout << (*ret) << endl;
}