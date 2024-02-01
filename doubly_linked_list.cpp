#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *pre;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
};

template <class T>
class doublyLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertFront(T data)
    {
        Node<T> *xnode = new Node(data);
        if (head == NULL)
        {
            head = xnode;
            tail = xnode;
        }
        else
        {
            xnode->next = head;
            head->pre = xnode;
            head = head->pre;
        }
    }
    void insertBack(T data)
    {
        Node<T> *xnode = new Node(data);
        if (head == NULL)
        {
            head = xnode;
            tail = xnode;
        }
        else
        {
            tail->next = xnode;
            xnode->pre = tail;
            tail = tail->next;
        }
    }
    void insertAfter(T target, T data)
    {
        Node<T> *curr = head;
        while (curr && curr->data != target)
            curr = curr->next;
        if (curr == NULL)
        {
            cout << "target not found" << endl;
            return;
        }
        if (curr->next == NULL)
        {
            insertBack(data);
            return;
        }
        Node<T> *xnode = new Node(data);
        xnode->pre = curr;
        curr->next->pre = xnode;
        xnode->next = curr->next;
        curr->next = xnode;
    }
    void deleteFront()
    {
        Node<T> *temp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        else
            head->pre = NULL;
        delete temp;
    }
    void deleteBack()
    {
        Node<T> *temp = tail;
        tail = tail->pre;
        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;
        delete temp;
    }

    void print()
    {
        Node<T> *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    doublyLinkedList<int> dl;
    dl.insertBack(10);
    dl.insertFront(5);
    // dl.insertBack(15);
    // dl.insertFront(2);
    // dl.insertBack(20);
    dl.insertAfter(10, 17);
    dl.print();
    dl.deleteFront();
    dl.print();
    dl.deleteBack();
    dl.print();
}