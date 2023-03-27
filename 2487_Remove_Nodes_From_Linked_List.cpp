#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNodes(ListNode *head)
{
    stack<ListNode *> st;
    while (head)
    {
        st.push(head);
        head = head->next;
    }

    head = st.top();
    st.pop();
    head->next = NULL;
    ListNode *p = NULL;
    while (!st.empty())
    {
        if (st.top()->val >= head->val)
        {
            p = st.top();
            p->next = head;
            head = p;
        }
        st.pop();
    }
    return head;
}