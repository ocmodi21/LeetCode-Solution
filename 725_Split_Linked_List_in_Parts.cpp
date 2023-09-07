#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

int countSize(ListNode *head)
{
    ListNode *p = head;
    int counter = 0;
    while (p)
    {
        counter++;
        p = p->next;
    }

    return counter;
}

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> splittedList;
    int n = countSize(head);
    ListNode *p = head, *nextNode = p;
    int size = n / k, partition = n % k, ind = 1;

    while (ind <= partition && nextNode)
    {
        p = nextNode;
        splittedList.push_back(p);
        for (int i = 1; i <= size; i++)
            p = p->next;
        nextNode = p->next;
        p->next = NULL;
        ind++;
    }

    while (ind <= n - partition && nextNode)
    {
        p = nextNode;
        splittedList.push_back(p);
        for (int i = 1; i <= size - 1; i++)
            p = p->next;
        nextNode = p->next;
        p->next = NULL;
        ind++;
    }

    int diff = k - n;
    while (diff > 0)
    {
        splittedList.push_back(NULL);
        diff--;
    }

    return splittedList;
}