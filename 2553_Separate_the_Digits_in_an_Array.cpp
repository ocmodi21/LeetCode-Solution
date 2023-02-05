#include <bits/stdc++.h>
using namespace std;

vector<int> separateDigits(vector<int> &a)
{
    vector<int> digits;
    for (int i = 0; i < a.size(); i++)
    {
        vector<int> temp;
        while (a[i] > 0)
        {
            temp.push_back(a[i] % 10);
            a[i] /= 10;
        }
        reverse(temp.begin(), temp.end());
        for (auto j : temp)
            digits.push_back(j);
    }
    return digits;
}