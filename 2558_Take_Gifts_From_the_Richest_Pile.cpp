#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<long long> pq(gifts.begin(), gifts.end());
    while (k--)
    {
        long long temp = pq.top();
        pq.pop();
        temp = sqrt(temp);
        pq.push(temp);
    }
    long long leftGifts = 0;
    while (!pq.empty())
    {
        leftGifts += pq.top();
        pq.pop();
    }
    return leftGifts;
}