#include <bits/stdc++.h>
using namespace std;

class DataStream
{
    int x, n, m;

public:
    DataStream(int value, int k)
    {
        n = k;
        m = value;
        x = 0;
    }

    bool consec(int num)
    {
        if (num == m)
            x++;
        else
            x = 0;
        return x >= n;
    }
};