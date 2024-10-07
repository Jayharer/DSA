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
    Node<T> *parent;
    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

template <class T>
class Heap
{
public:
    Node<T> *root;
    Heap()
    {
        root = NULL;
    }
    void postorder(Node<T> *root);
    void levelOrder(Node<T> *root);
    void push(T x);
    void pop();
    T top();
    void hepify(Node<T> *curr);
    void hepifyDown(Node<T> *curr);
};
template <class T>
void Heap<T>::pop()
{
    if (root == NULL)
        return;
    cout << "delete ele : " << root->data << endl;
    if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return;
    }
    Node<T> *curr = root;
    while (curr->right || curr->left)
    {
        if (curr->left)
            curr = curr->left;
        else if (curr->right)
            curr = curr->right;
    }
    swap(root->data, curr->data);
    if (curr->parent->left == curr)
        curr->parent->left = NULL;
    else
        curr->parent->right = NULL;
    hepifyDown(root);
}

template <class T>
T Heap<T>::top()
{
    if (root == NULL)
        return -1;
    return root->data;
}

template <class T>
void Heap<T>::postorder(Node<T> *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

template <class T>
void Heap<T>::hepifyDown(Node<T> *curr)
{
    if (curr == NULL)
        return;
    if (curr->left && curr->left->data > curr->data)
    {
        swap(curr->data, curr->left->data);
        hepifyDown(curr->left);
    }
    if (curr->right && curr->right->data > curr->data)
    {
        swap(curr->data, curr->right->data);
        hepifyDown(curr->right);
    }
}

template <class T>
void Heap<T>::hepify(Node<T> *curr)
{
    while (curr->parent != NULL && curr->parent->data < curr->data)
    {
        swap(curr->data, curr->parent->data);
        curr = curr->parent;
    }
}

template <class T>
void Heap<T>::push(T x)
{
    Node<T> *nodex = new Node(x);
    if (root == NULL)
    {
        root = nodex;
        return;
    }
    queue<Node<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<T> *curr = q.front();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        if (curr->left == NULL)
        {
            curr->left = nodex;
            nodex->parent = curr;
            hepify(curr->left);
            break;
        }
        else if (curr->right == NULL)
        {
            curr->right = nodex;
            nodex->parent = curr;
            hepify(curr->right);
            break;
        }
        q.pop();
    }
}

template <class T>
void Heap<T>::levelOrder(Node<T> *root)
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
    Heap<int> heap;
    heap.push(5);
    heap.push(10);
    heap.push(15);
    heap.push(20);
    // cout << "heap top : " << heap.top() << endl;
    heap.push(25);
    // cout << "heap top : " << heap.top() << endl;
    heap.push(30);
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    // cout << "heap top : " << heap.top() << endl;

    // heap.push(35);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(40);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(45);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(50);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(55);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(60);
    // cout << "heap top : " << heap.top() << endl;
    // heap.push(65);
    // cout << "heap top : " << heap.top() << endl;

    // heap.postorder(heap.root);
    heap.levelOrder(heap.root);
}