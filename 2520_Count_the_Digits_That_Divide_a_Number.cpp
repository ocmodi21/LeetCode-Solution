#include <bits/stdc++.h>
using namespace std;

int countDigits(int num)
{
    vector<int> temp;
    int t = num;
    int r;
    while (t > 0)
    {
        r = t % 10;
        t = t / 10;
        temp.push_back(r);
    }

    int count = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (num % temp[i] == 0)
            count++;
    }
    return count;
}