#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

int pairSum(ListNode *head)
{
    stack<int> st;
    int n = 0;
    ListNode *p = head;
    while (p)
    {
        st.push(p->val);
        n++;
        p = p->next;
    }
    p = head;

    if (n == 2)
        return (head->val + head->next->val);

    int ans = INT_MIN;
    while (n > 0 && p && !st.empty())
    {
        int sum = p->val + st.top();
        ans = max(ans, sum);
        st.pop();
        p = p->next;
        n -= 2;
    }
    return ans;
}