#include <bits/stdc++.h>
using namespace std;

vector<int> numMovesStones(int a, int b, int c)
{
    vector<int> stones = {a, b, c};
    sort(stones.begin(), stones.end());
    if (stones[2] - stones[0] == 2)
        return {0, 0};
    int mini = min((stones[1] - stones[0]), (stones[2] - stones[1]));
    if (mini <= 2)
        mini = 1;
    else
        mini = 2;
    int maxi = stones[2] - stones[0] - 2;
    return {mini, maxi};
}