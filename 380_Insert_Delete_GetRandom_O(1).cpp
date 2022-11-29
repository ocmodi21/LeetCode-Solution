#include <bits/stdc++.h>
using namespace std;

// Approch-1
unordered_map<int, int> mp;
vector<int> ans;

bool insert(int val)
{
    if (mp.find(val) != mp.end())
        return false;
    else
    {
        ans.push_back(val);
        mp[val] = ans.size() - 1;
        return true;
    }
}

bool remove(int val)
{
    if (mp.find(val) == mp.end())
        return false;
    else
    {
        int last = ans.back();
        ans[mp[val]] = ans.back();
        ans.pop_back();
        mp[last] = mp[val];
        mp.erase(val);
        return true;
    }
}

int getRandom()
{
    return ans[rand() % ans.size()];
}

// Approch-2
set<int> st;
bool insert(int val)
{
    if (!st.count(val))
    {
        st.insert(val);
        return true;
    }
    return false;
}

bool remove(int val)
{
    if (st.count(val))
    {
        st.erase(val);
        return true;
    }
    return false;
}

int getRandom()
{
    if (st.size() != 0)
    {
        return *next(st.begin(), rand() % st.size());
    }
    return 0;
}