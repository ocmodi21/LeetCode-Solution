#include <bits/stdc++.h>
using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
    long long low = 0, high = 1LL * *max_element(time.begin(), time.end()) * totalTrips, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < time.size(); i++)
            sum += mid / time[i];

        if (sum >= totalTrips)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}