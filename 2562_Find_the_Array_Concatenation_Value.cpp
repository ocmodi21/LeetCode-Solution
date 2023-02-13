#include <bits/stdc++.h>
using namespace std;

long long findTheArrayConcVal(vector<int> &nums)
{
    long long concateValue = 0;
    int i = 0, j = nums.size() - 1;

    while (i < j)
    {
        string temp1 = to_string(nums[i]);
        string temp2 = to_string(nums[j]);
        string temp = temp1 + temp2;
        concateValue += stoi(temp);
        i++;
        j--;
    }
    if (nums.size() % 2 != 0)
        concateValue += nums[i];
    return concateValue;
}