#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : rooms[curr])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
        {
            return false;
        }
    }
    return true;
}
}
;