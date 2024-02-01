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
    void levelOrder(Node<T> *root);
    Node<T> *createBST(vector<int> arr);
    Node<T> *insert(Node<T> *root, T x);
    bool contains(Node<T> *root, T x);
    bool remove(Node<T> *&root, T x, stack<Node<T> *> &stk);
    bool update(Node<T> *&root, T x, T y);
    int noOfEdgesFromRoot(Node<T> *root, T x);
    // int noOfEdges(Node<T> *node1, Node<T> *node2);
};

// if node does not exist return -1
template <class T>
int bTree<T>::noOfEdgesFromRoot(Node<T> *root, T x)
{
    if (root == NULL)
        return -1;

    if (root->data == x)
        return 0;
    int res = -1;
    if (x < root->data)
        res = noOfEdgesFromRoot(root->left, x);
    else
        res = noOfEdgesFromRoot(root->right, x);
    if (res == -1)
        return res;
    return 1 + res;
}

template <class T>
bool bTree<T>::remove(Node<T> *&root, T x, stack<Node<T> *> &stk)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == x)
    {
        if (stk.empty())
        {
            if (root->left && root->right)
            {
                Node<T> *curr = root;
                curr = root->right;
                while (curr->left)
                    curr = curr->left;
                curr->left = root->left;
                root = root->right;
            }
            else if (root->left)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            return 1;
        }
        else
        {
            Node<T> *temp = root;
            Node<T> *parent = stk.top();
            bool isLeft = root == parent->left ? true : false;
            if (root->left == NULL && root->right == NULL)
            {
                if (isLeft)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else if (root->left == NULL || root->right == NULL)
            {
                if (isLeft)
                {
                    if (root->left != NULL)
                        parent->left = root->left;
                    else
                        parent->left = root->right;
                }
                else
                {
                    if (root->left != NULL)
                        parent->right = root->left;
                    else
                        parent->right = root->right;
                }
            }
            else
            {
                Node<T> *curr = root;
                curr = root->right;
                while (curr->left)
                    curr = curr->left;
                curr->left = root->left;
                if (isLeft)
                    parent->left = root->right;
                else
                    parent->right = root->right;
            }
            delete temp;
            return 1;
        }
    }
    else
    {
        stk.push(root);
        if (x > root->data)
            return remove(root->right, x, stk);
        else
            return remove(root->left, x, stk);
    }
}

template <class T>
bool bTree<T>::update(Node<T> *&root, T x, T y)
{
    stack<Node<T> *> stk;
    bool res = remove(root, x, stk);
    if (res)
    {
        insert(root, y);
        return 1;
    }
    return 0;
}

template <class T>
bool bTree<T>::contains(Node<T> *root, T x)
{
    if (root == NULL)
        return 0;
    if (root->data == x)
        return 1;
    int search = 0;
    if (x < root->data)
        search = contains(root->left, x);
    if (search)
        return 1;
    search = contains(root->right, x);
    return search;
}

template <class T>
Node<T> *bTree<T>::insert(Node<T> *root, T x)
{
    if (root == NULL)
    {
        Node<T> *xnode = new Node(x);
        return xnode;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

template <class T>
Node<T> *bTree<T>::createBST(vector<int> arr)
{
    Node<T> *root = NULL;
    for (int i = 0; i < arr.size(); i++)
        root = insert(root, arr[i]);
    return root;
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

int main()
{
    bTree<int> bst;

    vector<int> arr = {10, 5, 2, 15, 20, 6};
    Node<int> *root = bst.createBST(arr);

    cout << bst.noOfEdgesFromRoot(root, 10) << endl;
    cout << bst.noOfEdgesFromRoot(root, 5) << endl;
    cout << bst.noOfEdgesFromRoot(root, 2) << endl;
    cout << bst.noOfEdgesFromRoot(root, 1) << endl;

    // vector<int> arr2 = {898, 88, 8928};
    // bst.levelOrder(root);
    // for (auto val : arr2)
    //     cout << bst.contains(root, val) ? "true" : "false";

    // bst.levelOrder(root);
    // stack<Node<int> *> stk;
    // bst.remove(root, 10, stk);
    // bst.levelOrder(root);

    // bst.levelOrder(root);
    // bst.update(root, 5, 15);
    // bst.levelOrder(root);
}