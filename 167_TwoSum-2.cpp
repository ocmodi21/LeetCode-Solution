#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> v;
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j)
    {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
        {
            v.push_back(i + 1);
            v.push_back(j + 1);
            break;
        }
        else if (sum < target)
            i++;
        else
            j--;
    }
    return v;
}