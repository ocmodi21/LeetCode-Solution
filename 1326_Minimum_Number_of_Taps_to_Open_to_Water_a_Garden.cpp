#include <bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int> &ranges)
{
    vector<int> maxReach(n + 1, 0);
    int counter = 0;

    for (int i = 0; i <= n; i++)
    {
        int start = max(0, i - ranges[i]);
        int end = min(n, ranges[i] + i);

        maxReach[start] = max(maxReach[start], end);
    }

    int currentEnd = 0, nextEnd = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i > nextEnd)
            return -1;

        if (i > currentEnd)
        {
            counter++;
            currentEnd = nextEnd;
        }
        nextEnd = max(maxReach[i], nextEnd);
    }
    return counter;
}