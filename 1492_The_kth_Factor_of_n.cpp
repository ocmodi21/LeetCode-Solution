#include <bits/stdc++.h>
using namespace std;

int kthFactor(int n, int k)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }
    return ans.size() < k ? -1 : ans[k - 1];
}