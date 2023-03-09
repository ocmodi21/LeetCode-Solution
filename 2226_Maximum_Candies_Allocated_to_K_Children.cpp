#include <bits/stdc++.h>
using namespace std;

int maximumCandies(vector<int> &candies, long long k)
{
    long long sum = 0, max = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        sum += candies[i];
        if (max < candies[i])
            max = candies[i];
    }
    if (sum < k)
        return 0;

    long long low = 1, high = max * 1LL, mid;
    long long maxCandies = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        long long count = 0;
        for (int i = 0; i < candies.size(); i++)
            count += candies[i] / mid;

        if (count < k)
            high = mid - 1;
        else
        {
            low = mid + 1;
            maxCandies = mid;
        }
    }
    return maxCandies;
}