#include <bits/stdc++.h>
using namespace std;

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
{
    int ans = 0;
    while (numOnes > 0 && k > 0)
    {
        k--;
        numOnes--;
        ans++;
    }
    while (numZeros > 0 && k > 0)
    {
        k--;
        numZeros--;
    }
    while (numNegOnes > 0 && k > 0)
    {
        k--;
        numNegOnes--;
        ans--;
    }
    return ans;
}