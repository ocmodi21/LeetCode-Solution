#include <bits/stdc++.h>
using namespace std;

vector<int> getStrongest(vector<int> &arr, int k)
{
    if (arr.size() == 1)
        return {arr[0]};

    sort(arr.begin(), arr.end());
    int mid = arr[(arr.size() - 1) / 2];
    vector<int> ans;
    int start = 0, end = arr.size() - 1;

    for (int i = 0; i < k; i++)
    {
        if (abs(arr[start] - mid) <= abs(arr[end] - mid))
        {
            ans.push_back(arr[end]);
            end--;
        }
        else
        {
            ans.push_back(arr[start]);
            start++;
        }
    }
    return ans;
}