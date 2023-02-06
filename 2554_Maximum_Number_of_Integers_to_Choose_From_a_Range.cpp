#include <bits/stdc++.h>
using namespace std;

int maxCount(vector<int> &banned, int n, int maxSum)
{
    vector<bool> validNumbers(n + 1, true);
    int counter = 0, sum = 0;
    for (int i = 0; i < banned.size(); i++)
    {
        if (banned[i] <= n)
            validNumbers[banned[i]] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (validNumbers[i])
        {
            sum += i;
            if (sum <= maxSum)
                counter++;
            else
                break;
        }
    }
    return counter;
}