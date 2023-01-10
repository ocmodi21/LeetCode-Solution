#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

int findInMountainArray(int target, MountainArray &mountainArr)
{
    int n = mountainArr.length();
    int start = 0;
    int end = n - 1;
    int peak;

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            start = mid + 1;
        else
            end = mid;
    }
    peak = start;

    cout << peak << endl;

    int low1 = 0;
    int high1 = peak;
    int ind1 = -1;

    while (low1 <= high1)
    {
        int mid = (low1 + high1) / 2;
        if (mountainArr.get(mid) == target)
        {
            ind1 = mid;
            return ind1;
        }
        else if (mountainArr.get(mid) > target)
            high1 = mid - 1;
        else
            low1 = mid + 1;
    }

    int low2 = peak;
    int high2 = n - 1;
    int ind2 = -1;

    while (low2 <= high2)
    {
        int mid = (low2 + high2) / 2;
        if (mountainArr.get(mid) == target)
        {
            ind2 = mid;
            return ind2;
        }
        else if (mountainArr.get(mid) > target)
            low2 = mid + 1;
        else
            high2 = mid - 1;
    }
    return -1;
}