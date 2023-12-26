#include <iostream>
#include <algorithm>
using namespace std;

// AVL ����ƽ����
template <typename T>
class AVLTree
{
public:
    // AVL�ĳ�ʼ��
    AVLTree() : root_(nullptr) {}
    ~AVLTree() {}

    // AVL���Ĳ������
    void insert(const T &val)
    {
        root_ = insert(root_, val); // �����ǿ������ʸ��¿սڵ�
    }
    // AVL����ɾ������
    void remove(const T &val)
    {
        root_ = remove(root_, val);
    }

    // �ݹ������������
    void inOrder()
    {
        cout << "[�ݹ�]�������: " << endl;
        inOrder(root_);
        cout << endl;
    }

private:
    // ����AVL���ڵ�����
    struct Node
    {
        Node(T data = T())
            : data_(data), left_(nullptr), right_(nullptr), height_(1) {}

        T data_;
        Node *left_;
        Node *right_;
        int height_; // ��¼�ڵ�ĸ߶�ֵ
    };

    Node *root_;

private:
    // ���ؽڵ�ĸ߶�ֵ
    int height(Node *node)
    {
        return node == nullptr ? 0 : node->height_;
    }
    // ����ת���� �Բ���nodeΪ��������ת�����������µĸ��ڵ㷵��
    Node *rightRotate(Node *node)
    {
        // �ڵ���ת
        Node *child = node->left_;   // ��ýڵ�����ӣ�������������Ϊ�¸��ڵ�
        node->left_ = child->right_; // ����õ�child���Һ��ӹ���ԭchild��λ��
        child->right_ = node;        // ���ڵ����child���Һ���
        // �߶ȸ���
        node->height_ = max(height(node->left_), height(node->right_)) + 1;
        child->height_ = max(height(child->left_), height(child->right_)) + 1;
        // ������ת��������µĸ��ڵ�
        return child;
    }
    // ����ת���� �Բ���nodeΪ��������ת�����������µĸ��ڵ㷵��
    Node *leftRotate(Node *node)
    {
        // �ڵ���ת
        Node *child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        node->height_ = max(height(node->left_), height(node->right_)) + 1;
        child->height_ = max(height(child->left_), height(child->right_)) + 1;
        // ������ת��������µĸ��ڵ�
        return child;
    }
    // ��ƽ����� �Բ���nodeΪ������-����ת�����������µĸ��ڵ㷵��
    Node *leftBalance(Node *node)
    {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }
    // ��ƽ����� �Բ���nodeΪ������-����ת�����������µĸ��ڵ㷵��
    Node *rightBalance(Node *node)
    {
        node->right_ = leftRotate(node->right_);
        return rightRotate(node);
    }
    // �������
    Node *insert(Node *node, const T &val)
    {
        if (node == nullptr) // �ݹ��������
            node = new Node(val);

        if (node->data_ > val)
        {
            node->left_ = insert(node->left_, val); // Ҫ���ڵ㷵��
            // ���BST��Ĳ�:
            // ���1 �ڵݹ����ʱ�жϽڵ��Ƿ�ʧ��  node��������̫�� nodeʧ����
            if (height(node->left_) - height(node->right_) > 1)
            {
                if (height(node->left_->left_) > height(node->left_->right_))
                {
                    // �ڵ�ʧ�⣬�������ӵ�������̫��
                    node = rightRotate(node);
                }
                else
                {
                    // �ڵ�ʧ�⣬�������ӵ�������̫��
                    node = leftBalance(node);
                }
            }
        }
        else if (node->data_ < val)
        {
            node->right_ = insert(node->right_, val);
            // ���2 �ڵݹ����ʱ�жϽڵ��Ƿ�ʧ��  node��������̫�� nodeʧ����
            if (height(node->right_) - height(node->left_) > 1)
            {
                if (height(node->right_->right_) >= height(node->right_->left_))
                {
                    // �ڵ�ʧ�⣬�����Һ��ӵ�������̫��
                    node = leftRotate(node);
                }
                else
                {
                    // �ڵ�ʧ�⣬�����Һ��ӵ�������̫��
                    node = rightBalance(node);
                }
            }
        }
        else
        {
            ; // �ҵ���ͬ�ڵ��ˣ����������µݹ��ˣ�ֱ�����ϻ���
        }
        // ���3 ��Ϊ�������������µĽڵ�  �ڵݹ����ʱ�����½ڵ�߶�
        node->height_ = max(height(node->left_), height(node->right_)) + 1;

        return node;
    }
    // AVL����ɾ������
    Node *remove(Node *node, const T &val)
    {
        if (node == nullptr)
            return nullptr;
        // �ҵ���ɾ�ڵ�
        if (node->data_ > val)
        {
            node->left_ = remove(node->left_, val);
            // ������ɾ���ڵ㣬�������������̫��
            if (height(node->right_) - height(node->left_) > 1)
            {
                if (height(node->right_->right_) >= height(node->right_->left_))
                {
                    // �Һ��ӵ�������̫��
                    node = leftRotate(node);
                }
                else
                {
                    // �Һ��ӵ�������̫��
                    node = rightBalance(node);
                }
            }
        }
        else if (node->data_ < val)
        {
            node->right_ = remove(node->right_, val);
            // ������ɾ���ڵ㣬���ܵ���������̫��
            if (height(node->left_) - height(node->right_) > 1)
            {
                if (height(node->left_->left_) >= height(node->left_->right_))
                {
                    // ���ӵ�������̫��
                    node = rightRotate(node);
                }
                else
                {
                    // ���ӵ�������̫��
                    node = leftBalance(node);
                }
            }
        }
        else // �ҵ���
        {
            // �ҵ��� �ȴ������������ӵĽڵ�ɾ�����
            if (node->left_ != nullptr && node->right_ != nullptr)
            {
                // Ϊ�˱���ɾ��ǰ�����ߺ�̽ڵ���ɽڵ�ʧ�⣬˭��ɾ��˭
                if (height(node->left_) >= height(node->right_))
                {
                    // ɾǰ��
                    Node *pre = node->left_;
                    while (pre->right_ != nullptr)
                        pre = pre->right_;
                    // ��ǰ�����Ǵ�ɾ�ڵ�
                    node->data_ = pre->data_;
                    node->left_ = remove(node->left_, pre->data_); // ɾ��ǰ���ڵ�
                }
                else
                {
                    // ɾ���
                    Node *post = node->right_;
                    while (post->left_ != nullptr)
                        post = post->left_;
                    // �ú�̸��Ǵ�ɾ�ڵ�
                    node->data_ = post->data_;
                    node->right_ = remove(node->right_, post->data_); // ɾ����̽ڵ�
                }
            }
            else // ɾ���ڵ㣬�����һ������
            {
                // �жϴ�ɾ�ڵ�ĺ�����������
                if (node->left_ != nullptr)
                {
                    // ɾ���ڵ��Ժ󣬰ѷǿյ����ӷ��أ�����ʱ�����丸�ڵ��ַ��
                    Node *left = node->left_;
                    delete node;
                    return left;
                }
                else if (node->right_ != nullptr)
                {
                    // ɾ���ڵ��Ժ󣬰ѷǿյ��Һ��ӷ��أ�����ʱ�����丸�ڵ��ַ��
                    Node *left = node->left_;
                    delete node;
                    return left;
                }
                else // ɾ������û�к��ӵĽڵ�  Ҷ�ӽڵ�
                {
                    return nullptr; // ����ʱ�����丸�ڵ��ַ��Ϊnullptr
                }
            }
        }
        // ���½ڵ�߶�
        node->height_ = max(height(node->left_), height(node->right_)) + 1;
        return node; // �ݹ���ݹ����У��ѵ�ǰ�ڵ�����ڵ㷵��
    }
    // �ݹ����������ʵ��  LVR
    void inOrder(Node *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left_);       // L
            cout << node->data_ << " "; // V
            inOrder(node->right_);      // R
        }
    }
};
int main()
{
    AVLTree<int> avl;
    for (int i = 0; i != 10; ++i)
        avl.insert(i);
    avl.inOrder();

    avl.remove(6);
    avl.inOrder();
    avl.remove(7);
    avl.inOrder();
    avl.remove(8);
    avl.inOrder();

    system("pause");
    return 0;
}