#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> pq;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<int> topo;
    while (!pq.empty())
    {
        int curr = pq.front();
        topo.push_back(curr);
        pq.pop();

        for (int it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                pq.push(it);
            }
        }
    }

    if (topo.size() == numCourses)
        return topo;
    return {};
}