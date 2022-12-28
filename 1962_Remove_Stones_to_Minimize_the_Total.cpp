#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq(piles.begin(), piles.end());

    int sum = 0;
    for (int i = 0; i < piles.size(); i++)
        sum += piles[i];

    while (!pq.empty() && k--)
    {
        int curr = pq.top();
        pq.pop();
        sum -= floor(curr / 2);
        curr -= floor(curr / 2);
        pq.push(curr);
    }
    return sum;
}