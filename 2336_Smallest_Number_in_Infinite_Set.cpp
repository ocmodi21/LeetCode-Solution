#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
public:
    map<int, int> mp;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
            mp[i]++;
    }

    int popSmallest()
    {
        int temp = mp.begin()->first;
        mp.erase(temp);
        return temp;
    }

    void addBack(int num)
    {
        mp[num]++;
    }
};

