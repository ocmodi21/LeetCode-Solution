#include <bits/stdc++.h>
using namespace std;

long long makeSubKSumEqual(vector<int> &arr, int k)
{
    long long ans = 0;
    int n = arr.size();
    k = __gcd(k, n);

    for (int i = 0; i < k; i++)
    {
        vector<int> v;
        for (int j = i; j < n; j += k)
        {
            v.push_back(arr[j]);
        }

        sort(v.begin(), v.end());
        long long midv = v[v.size() / 2];
        for (int j = i; j < n; j += k)
        {
            ans += abs(midv - arr[j]);
        }
    }
    return ans;
}