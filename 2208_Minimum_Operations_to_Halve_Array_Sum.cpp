#include <bits/stdc++.h>
using namespace std;

int halveArray(vector<int> &nums)
{
    priority_queue<double> pq;
    double totalSum = 0;
    for (auto ele : nums)
    {
        totalSum += ele;
        pq.push(ele);
    }

    double halftotalSum = totalSum / 2;
    int minOperation = 0;
    while (totalSum > halftotalSum)
    {
        double max = pq.top();
        pq.pop();
        max /= 2;
        pq.push(max);
        minOperation++;
        totalSum -= max;
    }
    return minOperation;
}