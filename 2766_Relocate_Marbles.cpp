#include <bits/stdc++.h>
using namespace std;

// Approch - 1
vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
{
    map<int, int> pos;
    for (int i = 0; i < nums.size(); i++)
        pos[nums[i]]++;

    for (int i = 0; i < moveFrom.size(); i++)
    {
        int from = moveFrom[i];
        int to = moveTo[i];

        if (pos.count(from))
        {
            int marble = pos[from];
            pos.erase(from);
            pos[to] = marble;
        }
    }

    vector<int> ans;
    for (auto [first, second] : pos)
        ans.push_back(first);
    return ans;
}

// Approch - 2
vector<int> relocateMarbles(vector<int> &a, vector<int> &moveFrom, vector<int> &moveTo)
{
    vector<int> occupied;
    set<int> st(a.begin(), a.end());

    for (int i = 0; i < moveFrom.size(); i++)
    {
        st.erase(st.find(moveFrom[i]));
        st.insert(moveTo[i]);
    }

    for (auto i : st)
        occupied.push_back(i);
    return occupied;
}
