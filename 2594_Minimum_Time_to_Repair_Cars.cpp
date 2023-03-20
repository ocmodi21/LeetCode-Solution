#include <bits/stdc++.h>
using namespace std;

bool isRepair(vector<int> &ranks, long long mid, long long cars)
{
    long long repair = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        repair += sqrt(mid / ranks[i]);
    }
    return repair >= cars;
}
long long repairCars(vector<int> &ranks, int cars)
{
    long long low = 1, high = 1e18;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isRepair(ranks, mid, cars))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}