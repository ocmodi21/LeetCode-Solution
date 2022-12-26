#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += cardPoints[i];

    int res = ans;
    for (int i = k - 1; i >= 0; i--)
    {
        res -= cardPoints[i];
        res += cardPoints[n - k + i];
        ans = max(ans, res);
    }
    return ans;
}