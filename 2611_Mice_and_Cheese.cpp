#include <bits/stdc++.h>
using namespace std;

// Apprcoh-1
int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
{
    vector<int> v;
    long long sum = 0;
    for (int i = 0; i < reward1.size(); i++)
    {
        v.push_back(reward1[i] - reward2[i]);
        sum += reward2[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < k; i++)
        sum += v[i];
    return sum;
}

// Approch-2
int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    for (int i = 0; i < reward1.size(); i++)
    {
        pq.push(reward1[i] - reward2[i]);
        sum += reward2[i];
        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}