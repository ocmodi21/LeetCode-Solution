#include <bits/stdc++.h>
using namespace std;

// Approch-1
int alternateDigitSum(int num)
{
    int sum = 0;
    vector<int> ans;
    while (num > 0)
    {
        int mod = num % 10;
        num = num / 10;
        ans.push_back(mod);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i % 2 != 0)
            sum -= ans[i];
        else
            sum += ans[i];
    }
    return sum;
}

// Approch-2
int alternateDigitSum(int n)
{
    int size = trunc(log10(n)) + 1;
    int sign;
    if (size % 2 != 0)
        sign = 1;
    else
        sign = -1;
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += sign * digit;
        sign = -sign;
        n /= 10;
    }
    return sum;
}