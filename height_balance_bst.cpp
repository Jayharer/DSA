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
    int bf;
    Node<T> *left;
    Node<T> *right;

    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->bf = 0;
    }
};

template <class T>
class Hbst
{
public:
    void preorder(Node<T> *root);
    void inorder(Node<T> *root);
    void postorder(Node<T> *root);
    void levelOrder(Node<T> *root);
    Node<T> *createBST(vector<int> arr);
    Node<T> *insert(Node<T> *root, T x);
};

template <class T>
Node<T> *Hbst<T>::insert(Node<T> *root, T x)
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
Node<T> *Hbst<T>::createBST(vector<int> arr)
{
    Node<T> *root = NULL;
    for (int i = 0; i < arr.size(); i++)
        root = insert(root, arr[i]);
    return root;
}

template <class T>
void Hbst<T>::preorder(Node<T> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

template <class T>
void Hbst<T>::inorder(Node<T> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

template <class T>
void Hbst<T>::postorder(Node<T> *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

template <class T>
void Hbst<T>::levelOrder(Node<T> *root)
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
}