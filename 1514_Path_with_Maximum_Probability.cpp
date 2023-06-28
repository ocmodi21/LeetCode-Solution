#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<pair<int, double>> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    vector<double> pro(n + 1, 0);
    priority_queue<pair<double, int>> pq;
    pro[start] = 1;
    pq.push({1, start});
    while (!pq.empty())
    {
        int node = pq.top().second;
        double p = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            if (pro[it.first] < (it.second * pro[node]))
            {
                pro[it.first] = it.second * pro[node];
                pq.push({pro[it.first], it.first});
            }
        }
    }
    return pro[end];
}