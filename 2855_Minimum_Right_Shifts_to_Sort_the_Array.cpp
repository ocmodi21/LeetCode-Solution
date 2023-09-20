#include <bits/stdc++.h>
using namespace std;

int minimumRightShifts(vector<int> &nums)
{
    deque<int> a(nums.begin(), nums.end());
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (is_sorted(a.begin(), a.end()))
            return i;
        a.push_front(a.back());
        a.pop_back();
    }
    return -1;
}