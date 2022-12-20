#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, maxi = 0;

    while (i < n - 2)
    {
        int j = i + 1;
        if (arr[i] < arr[j])
        {
            while (j < n - 1 && arr[j] < arr[j + 1])
            {
                j++;
            }
            while (j < n - 1 && arr[j] > arr[j + 1])
            {
                j++;
                maxi = max(maxi, j - i + 1);
            }
        }
        i = j;
    }
    return maxi;
}