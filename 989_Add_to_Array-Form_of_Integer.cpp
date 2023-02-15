#include <bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int temp = num[i] + k;
        num[i] = temp % 10;
        k = temp / 10;
    }
    while (k > 0)
    {
        num.insert(num.begin(), k % 10);
        k = k / 10;
    }
    return num;
}