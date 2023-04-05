#include <bits/stdc++.h>
using namespace std;

bool isMinimum(int mid, vector<int> a)
{
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum > (long long)mid * (i + 1))
            return false;
    }
    return true;
}
int minimizeArrayValue(vector<int> &a)
{
    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isMinimum(mid, a))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}