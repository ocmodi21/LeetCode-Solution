#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL){};
};

class MyLinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index)
    {
        if (index > size)
            return -1;
        Node *temp = head;
        int counter = 0;
        while (temp)
        {
            if (counter++ == index)
                return temp->val;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *temp = new Node(val);
        if (tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            if (count++ == index - 1)
            {
                Node *mid = new Node(val);
                mid->next = temp->next;
                temp->next = mid;
                break;
            }
            temp = temp->next;
        }
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        if (index == 0)
            head = head->next;
        else if (index == size - 1)
        {
            int count = 0;
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;
            temp->next = temp->next->next;
            tail = temp;
        }
        else
        {
            int count = 0;
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;
            temp->next = temp->next->next;
        }
        size--;
    }
};