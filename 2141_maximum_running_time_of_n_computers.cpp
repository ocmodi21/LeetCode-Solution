#include <bits/stdc++.h>
using namespace std;

// Approch - 1
long long maxRunTime(int n, vector<int> &batteries)
{
    long long low = 1;
    long long high = accumulate(begin(batteries), end(batteries), 0LL) / n;

    while (low < high)
    {
        long long mid = (high + low + 1) / 2;
        long long time = 0;

        for (auto it : batteries)
            time += min((long long)it, mid);

        if (mid * n <= time)
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}

// Approch - 2
long long maxRunTime(int n, vector<int> &b)
{
    int m = b.size();
    sort(b.begin(), b.end());
    long long sum = accumulate(begin(b), end(b), 0LL);
    int i = m - 1;
    while (i >= 0 && sum / n < b[i])
    {
        sum -= b[i];
        n--;
        i--;
    }
    return sum / n;
}