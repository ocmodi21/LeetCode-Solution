#include <bits/stdc++.h>
using namespace std;

vector<int> circularGameLosers(int n, int k)
{
    vector<int> received(n, false);
    vector<int> losers;
    received[0] = true;
    bool flag = true;
    int i = 1, ind = 0;
    while (flag)
    {
        ind = (ind + i * k) % n;
        if (received[ind])
            flag = false;
        received[ind] = true;
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (!received[i])
            losers.push_back(i + 1);
    }
    return losers;
}