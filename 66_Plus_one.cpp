#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Space Complexity o(n)
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
            v.push_back(digits[i]);
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
}

// Approch-2 =>Space Complexity o(1)
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }

    digits.push_back(0);
    digits[0] = 1;
    return digits;
}