#include <bits/stdc++.h>
using namespace std;

int differenceOfSum(vector<int> &nums)
{
    int elementSum = 0, digitSum = 0;
    for (int v : nums)
    {
        elementSum += v;
        while (v)
        {
            digitSum += v % 10;
            v /= 10;
        }
    }
    return abs(elementSum - digitSum);
}