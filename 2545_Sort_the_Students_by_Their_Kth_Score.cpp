#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    int n = score.size();
    int m = score[0].size();
    if (m < k)
        return score;

    vector<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push_back({score[i][k], i});
    }
    sort(pq.begin(), pq.end());
    reverse(pq.begin(), pq.end());
    vector<vector<int>> ans;
    int j = 0;
    while (n--)
    {
        int x = pq[j].second;
        ans.push_back(score[x]);
        j++;
    }
    return ans;
}

// Approch-2
vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    int m = score.size();
    int n = score.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (score[i][k] < score[j][k])
                swap(score[i], score[j]);
        }
    }
    return score;
}