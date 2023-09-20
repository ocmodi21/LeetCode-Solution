#include <bits/stdc++.h>
using namespace std;

bool decToBinary(int n, int k)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    int count = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (binaryNum[j] == 1)
            count++;
    }
    return count == k;
}

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (decToBinary(i, k))
        {
            sum += nums[i];
        }
    }
    return sum;
}