#include <bits/stdc++.h>
using namespace std;

// Approch-1
int maxWidthRamp(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] <= nums[j])
                ans = max(ans, j - i);
        }
    }
    return ans;
}

// Approch-2
int maxWidthRamp(vector<int> &nums)
{
    stack<int> st;
    int maxRamp = 0;
    st.push(0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[st.top()] > nums[i])
            st.push(i);
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            maxRamp = max(maxRamp, i - st.top());
            st.pop();
        }
    }
    return maxRamp;
}