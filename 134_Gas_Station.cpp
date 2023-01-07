#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int gasSum = 0, costSum = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        gasSum += gas[i];
        costSum += cost[i];
    }
    if (gasSum < costSum)
        return -1;

    int total = 0;
    int startInd = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total += (gas[i] - cost[i]);
        if (total < 0)
        {
            total = 0;
            startInd = i + 1;
        }
    }
    return startInd;
}