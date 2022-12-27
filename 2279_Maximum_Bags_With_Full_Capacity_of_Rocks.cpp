#include <bits/stdc++.h>
using namespace std;

int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
{
    for (int i = 0; i < capacity.size(); i++)
    {
        capacity[i] -= rocks[i];
    }
    int count = 0;
    sort(capacity.begin(), capacity.end());
    for (int i = 0; i < capacity.size(); i++)
    {
        if (additionalRocks < capacity[i])
            break;
        additionalRocks -= capacity[i];
        count++;
    }
    return count;
}