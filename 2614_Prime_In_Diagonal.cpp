#include <bits/stdc++.h>
using namespace std;

int diagonalPrime(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<bool> Prime(4e6 + 1, true);
    Prime[0] = Prime[1] = false;
    for (int i = 2; i <= sqrt(4e6); i++)
    {
        if (Prime[i])
        {
            for (int j = i * i; j <= 4e6; j += i)
            {
                Prime[j] = false;
            }
        }
    }

    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        if (Prime[nums[i][i]])
        {
            maxAns = max(maxAns, nums[i][i]);
        }
        if (Prime[nums[i][n - i - 1]])
        {
            maxAns = max(maxAns, nums[i][n - i - 1]);
        }
    }
    return maxAns;
}