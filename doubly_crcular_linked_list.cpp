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
class doublyCircularLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    doublyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void createHead(Node<T> *xnode)
    {
        xnode->next = xnode;
        xnode->pre = xnode;
        head = xnode;
        tail = xnode;
    }

    void insertBack(T data)
    {
        Node<T> *xnode = new Node<T>(data);
        if (head == NULL)
        {
            createHead(xnode);
        }
        else
        {
            xnode->next = tail->next;
            tail->next = xnode;
            xnode->pre = tail;
            tail = tail->next;
            head->pre = tail;
        }
    }
    void insertFront(T data)
    {
        Node<T> *xnode = new Node(data);
        if (head == NULL)
        {
            createHead(xnode);
        }
        else
        {
            xnode->next = head;
            xnode->pre = tail;
            head->pre = xnode;
            head = head->pre;
            tail->next = head;
        }
    }
    void deleteFront()
    {
        Node<T> *temp = head;
        if (head == NULL)
            return;
        if (head->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->pre = tail;
            tail->next = head;
        }
        delete temp;
    }
    void deleteBack()
    {
        Node<T> *temp = tail;
        if (head == NULL)
            return;
        if (head->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->pre;
            tail->next = head;
            head->pre = tail;
        }
        delete temp;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "empty list";
        }
        else
        {
            Node<T> *curr = head;
            do
            {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);
        }
        cout << endl;
    }
};

int main()
{
    doublyCircularLinkedList<int> dcl;
    dcl.insertBack(10);
    dcl.insertFront(5);
    dcl.insertBack(15);
    dcl.print();
    dcl.deleteBack();
    dcl.print();
    // dcl.deleteBack();
    // dcl.print();
    // dcl.deleteBack();
    // dcl.print();
    dcl.deleteFront();
    dcl.print();
    dcl.deleteFront();
    dcl.print();
    dcl.insertBack(50);
    dcl.print();
    dcl.insertFront(25);
    dcl.print();
    dcl.insertFront(20);
    dcl.print();
    dcl.insertBack(75);
    dcl.print();
}