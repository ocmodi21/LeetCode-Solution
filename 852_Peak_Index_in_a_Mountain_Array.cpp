#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int l = 0;
    int h = n - 1;

    while (l < h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            l = mid;
        else
            h = mid + 1;
    }
    return -1;
}