#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums)
{
    set<int> st;
    for (auto it : nums)
        st.insert(it);
    nums.clear();
    for (auto it : st)
        nums.push_back(it);
    if (nums.size() < 3)
        return nums[nums.size() - 1];
    return nums[nums.size() - 3];
}