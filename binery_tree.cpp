#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class T>
class bTree
{
public:
    void preorder(Node<T> *root);
    void inorder(Node<T> *root);
    void postorder(Node<T> *root);
    Node<T> *createBT(vector<int> arr);
    void levelOrder(Node<T> *root);
    int height(Node<T> *root);
    int countNodes(Node<T> *root);
    int countLeaves(Node<T> *root);
    void parentNode(Node<T> *root, stack<Node<T> *> &stk);
    Node<T> *copyBtree(Node<T> *root);
};

template <class T>
Node<T> *bTree<T>::copyBtree(Node<T> *root)
{
    if (root == NULL)
        return root;
    Node<T> *node = new Node(root->data);
    node->left = copyBtree(root->left);
    node->right = copyBtree(root->right);
    return node;
}

template <class T>
void bTree<T>::parentNode(Node<T> *root, stack<Node<T> *> &stk)
{
    if (root == NULL)
    {
        if (!stk.empty())
            stk.pop();
        return;
    }
    if (!stk.empty())
    {
        cout << "parent of " << root->data << " is : " << stk.top()->data << endl;
        stk.pop();
    }
    else
    {
        cout << "parent of root node : NULL" << endl;
    }
    stk.push(root);
    stk.push(root);
    parentNode(root->left, stk);
    parentNode(root->right, stk);
}

template <class T>
int bTree<T>::countLeaves(Node<T> *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int left = countLeaves(root->left);
    int right = countLeaves(root->right);
    return (left + right);
}

template <class T>
int bTree<T>::countNodes(Node<T> *root)
{
    if (root == NULL)
        return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return (1 + left + right);
}

template <class T>
int bTree<T>::height(Node<T> *root)
{
    if (root == NULL)
        return 0;
    int left = 1 + height(root->left);
    int right = 1 + height(root->right);
    return max(left, right);
}

template <class T>
void bTree<T>::preorder(Node<T> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

template <class T>
void bTree<T>::inorder(Node<T> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

template <class T>
void bTree<T>::postorder(Node<T> *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

template <class T>
void bTree<T>::levelOrder(Node<T> *root)
{
    if (root == NULL)
        return;
    queue<Node<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<T> *curr = q.front();
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        q.pop();
    }
    cout << endl;
}

template <class T>
Node<T> *bTree<T>::createBT(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return NULL;
    Node<T> *root = NULL;
    queue<Node<T> *> q;
    int i = 0;
    Node<T> *xnode = new Node(arr[i]);
    q.push(xnode);
    i++;
    while (!q.empty())
    {
        Node<T> *curr = q.front();
        if (root == NULL)
            root = curr;
        if (i < n)
        {
            Node<T> *xnode = new Node(arr[i]);
            curr->left = xnode;
            q.push(xnode);
            i++;
        }
        if (i < n)
        {
            Node<T> *xnode = new Node(arr[i]);
            curr->right = xnode;
            q.push(xnode);
            i++;
        }
        q.pop();
    }
    return root;
}

int main()
{
    bTree<int> bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node<int> *root = bt.createBT(arr);
    bt.levelOrder(root);
    // stack<Node<int> *> stk;
    // bt.parentNode(root, stk);
    Node<int> *root2 = bt.copyBtree(root);
    bt.levelOrder(root2);
}