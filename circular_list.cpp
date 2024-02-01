#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    void print(Node *);
};

template <class T>
void Node<T>::print(Node *head)
{
    if (head == NULL)
        return;
    Node<int> *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

template <class T>
class circularLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    circularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void deleteBack()
    {
        if (head == NULL)
            return;
        Node<T> *temp = tail;
        if (head == head->next)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node<T> *curr = head;
            while (curr->next != tail)
                curr = curr->next;
            curr->next = tail->next;
            tail = curr;
        }
        delete temp;
    }

    void deleteFront()
    {
        if (head == NULL)
            return;
        Node<T> *temp = head;
        if (head == head->next)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }

    void insertBack(T data)
    {
        if (head == NULL)
        {
            createFirstNode(data);
            return;
        }
        Node<T> *node = new Node<T>(data);
        node->next = tail->next;
        tail->next = node;
        tail = tail->next;
    }

    void createFirstNode(T data)
    {
        Node<T> *node = new Node<T>(data);
        node->next = node;
        head = node;
        tail = node;
    }

    void insertFront(T data)
    {
        if (head == NULL)
        {
            createFirstNode(data);
            return;
        }
        Node<T> *node = new Node<T>(data);
        node->next = tail->next;
        tail->next = node;
        head = tail->next;
    }

    void printList(Node<T> *head)
    {
        if (head == NULL)
        {
            cout << "cl is empty" << endl;
            return;
        }
        Node<int> *curr = head;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main()
{
    circularLinkedList<int> cl;
    cl.insertFront(10);
    cl.insertFront(5);
    cl.insertBack(15);
    cl.printList(cl.head);
    cl.deleteFront();
    cl.printList(cl.head);
    cl.deleteBack();
    cl.printList(cl.head);
    cl.deleteBack();
    cl.printList(cl.head);
    // cout << endl;
}

/*
int main()
{
    Node<int> *first = new Node(10);
    Node<int> *second = new Node(20);
    Node<int> *third = new Node(30);

    first->next = second;
    second->next = third;
    third->next = first;

    first->print(first);
    cout << endl;
}
*/