#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<pair<int, pair<int, int>>> pq;
    vector<vector<int>> ans(k);

    for (int i = 0; i < points.size(); i++)
    {
        int temp = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pq.push_back({temp, {points[i][0], points[i][1]}});
    }
    sort(pq.begin(), pq.end());
    for (int i = 0; i < k; i++)
    {
        ans[i].push_back(pq[i].second.first);
        ans[i].push_back(pq[i].second.second);
    }
    return ans;
}

// Approch-2
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> v;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < points.size(); i++)
    {
        int sq = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push({sq, {points[i][0], points[i][1]}});
    }
    int n = points.size() - k;

    while (n--)
    {
        pq.pop();
    }
    while (!pq.empty())
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        vector<int> ans = {p.second.first, p.second.second};
        v.push_back(ans);
    }

    return v;
}

// Approch-3
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    multimap<int, vector<int>> sortedCoordinates;
    vector<vector<int>> coordinates;
    for (int i = 0; i < points.size(); i++)
    {
        int distance = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        vector<int> coordinate(2);
        coordinate[0] = points[i][0];
        coordinate[1] = points[i][1];
        sortedCoordinates.insert({distance, coordinate});
    }
    auto i = sortedCoordinates.begin();
    while (k--)
    {
        coordinates.push_back(i->second);
        i++;
    }
    return coordinates;
}