#include <bits/stdc++.h>
using namespace std;

int captureForts(vector<int> &forts)
{
    vector<int> fortIndex;
    int max = 0;
    for (int i = 0; i < forts.size(); i++)
    {
        if (forts[i] == 1 || forts[i] == -1)
            fortIndex.push_back(i);
    }

    if (fortIndex.size())
    {
        for (int i = 0; i < fortIndex.size() - 1; i++)
        {
            if (forts[fortIndex[i]] + forts[fortIndex[i + 1]] == 0)
            {
                if (max < fortIndex[i + 1] - fortIndex[i] - 1)
                    max = fortIndex[i + 1] - fortIndex[i] - 1;
            }
        }
    }
    return max;
}