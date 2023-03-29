#include <bits/stdc++.h>
using namespace std;

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