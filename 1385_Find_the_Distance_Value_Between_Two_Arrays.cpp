#include <bits/stdc++.h>
using namespace std;

// Approch-1
bool isValid(vector<int> &arr, int target, int d)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (abs(arr[mid] - target) <= d)
        {
            return false;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return true;
}

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(arr2.begin(), arr2.end());

    int cnt = 0;
    for (auto num : arr1)
    {
        if (isValid(arr2, num, d))
        {
            cnt++;
        }
    }

    return cnt;
}

// Approch-2
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int counter = 0;
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < arr1.size(); i++)
    {
        int l = 0, h = arr2.size() - 1, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (abs(arr1[i] - arr2[mid]) <= d)
            {
                counter++;
                l = h + 1;
            }
            else if (arr2[mid] > arr1[i])
                h = mid - 1;
            else
                l = mid + 1;
        }
    }
    return arr1.size() - counter;
}