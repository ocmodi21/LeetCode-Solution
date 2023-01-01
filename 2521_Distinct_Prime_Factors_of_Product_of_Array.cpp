#include <bits/stdc++.h>
using namespace std;

int distinctPrimeFactors(vector<int> &nums)
{
    set<int> g;
    for (auto t : nums)
    {
        for (int i = 2; i * i <= t; ++i)
        {
            if (t % i == 0)
            {
                g.insert(i);
                while (t % i == 0)
                    t /= i;
            }
        }
        if (t > 1)
            g.insert(t);
    }
    return g.size();
}