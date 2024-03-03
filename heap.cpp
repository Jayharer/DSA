#include <iostream>
#include <assert.h>
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
    void push(T x);
    void pop();
    T top();
    void hepify(Node<T> *curr);
};
template <class T>
void Heap<T>::pop()
{
    if (root == NULL)
        return;
    Node<T> *curr = root;
    while (curr->right)
        curr = curr->right;
    swap(root->data, curr->data);
    curr->parent->right = NULL;
    delete curr;
    Node<T> *curr = root;
    while (true)
    {
        if (curr->left && curr->data < curr->left->data)
        {
            swap(curr->data, curr->left->data);
            curr = curr->left;
        }
        else if (curr->right && curr->data < curr->right->data)
        {
            swap(curr->data, curr->right->data);
            curr = curr->right;
        }
        else
        {
            break;
        }
    }
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

int main()
{
    Heap<int> heap;
    heap.push(5);
    heap.push(10);
    assert(heap.top() == 10);
    heap.push(15);
    assert(heap.top() == 15);
    heap.push(20);
    assert(heap.top() == 20);
    heap.push(25);
    assert(heap.top() == 25);
    heap.push(30);
    assert(heap.top() == 30);
    heap.push(35);
    assert(heap.top() == 35);
    heap.push(40);
    assert(heap.top() == 40);
    heap.push(45);
    assert(heap.top() == 45);
    heap.push(50);
    assert(heap.top() == 50);
    heap.push(55);
    assert(heap.top() == 55);
    heap.push(60);
    assert(heap.top() == 60);
    heap.push(65);
    assert(heap.top() == 65);
    heap.postorder(heap.root);
}