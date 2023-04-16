#include <bits/stdc++.h>
using namespace std;

vector<long long> findPrefixScore(vector<int> &nums)
{
    vector<long long> conver;
    int mx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mx = max(mx, nums[i]);
        conver.push_back(mx + nums[i]);
    }
    vector<long long> prefix;
    long long sum = 0;
    for (int i = 0; i < conver.size(); i++)
    {
        sum += conver[i];
        prefix.push_back(sum);
    }
    return prefix;
}