#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (st.empty())
            res[i % n] = -1;
        else if (!st.empty() && st.top() > nums[i % n])
        {
            res[i % n] = st.top();
        }
        else if (!st.empty() && st.top() <= nums[i % n])
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (st.empty())
                res[i % n] = -1;
            else
                res[i % n] = (st.top());
        }
        st.push(nums[i % n]);
    }
    return res;
}