#include <bits/stdc++.h>
using namespace std;

bool canReachInTime(vector<int> dist, int speed, double hour)
{
    double time = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        time = ceil(time);
        time += (dist[i] / (speed * 1.0));
    }
    if (time <= hour)
        return true;
    return false;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int low = 1, high = INT_MAX, mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (canReachInTime(dist, mid, hour))
            high = mid;
        else
            low = mid + 1;
    }
    if (low == INT_MAX)
        return -1;
    return low;
}