#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
int reverseNumber(int n)
{
    int reverse = 0;
    while (n)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}
int countNicePairs(vector<int> &a)
{
    unordered_map<int, int> pairMap;
    long long counter = 0;
    for (int i = 0; i < a.size(); i++)
        counter = (counter + pairMap[a[i] - reverseNumber(a[i])]++) % MOD;
    return counter;
}