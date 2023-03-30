#include <bits/stdc++.h>
using namespace std;

// Approch-1
int maxSatisfaction(vector<int> &satisfaction)
{
    int sum = 0, maxSatisfaction = 0;
    sort(satisfaction.begin(), satisfaction.end());
    for (int i = satisfaction.size() - 1; i >= 0; i--)
    {
        sum += satisfaction[i];
        if (sum < 0)
            return maxSatisfaction;
        maxSatisfaction += sum;
    }
    return maxSatisfaction;
}

// Approch-2
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}