#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high)
        {
            long int mid = low + (high - low) / 2;
            if (arr[i][mid] < 0)
            {
                last = mid;
                high = mid - 1;
            }
            else if (arr[i][mid] >= 0)
                low = mid + 1;
        }
        if (last != -1)
            cnt += (n - last);
    }
    return cnt;
}