#include <bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> &a, long long target)
{
    int l = 0, h = a.size() - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (a[mid] == target)
            return true;
        else if (a[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int longestSquareStreak(vector<int> &a)
{
    int max = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        int counter = 0;
        long long target = (long long)a[i] * a[i];
        while (isPresent(a, target))
        {
            counter++;
            target *= target;
        }
        if (max < counter)
            max = counter;
    }
    if (!max)
        return -1;
    return max + 1;
}