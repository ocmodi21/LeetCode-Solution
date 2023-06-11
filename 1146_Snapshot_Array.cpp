#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    vector<map<int, int>> v;
    int sid = 0;
    SnapshotArray(int length)
    {
        v.resize(length);
        for (int i = 0; i < length; i++)
            v[i][0] = 0;
    }

    void set(int index, int val)
    {
        v[index][sid] = val;
    }

    int snap()
    {
        sid++;
        return sid - 1;
    }

    int get(int index, int snap_id)
    {
        if (v[index].find(snap_id) == v[index].end())
        {
            auto it = --v[index].lower_bound(snap_id);
            return it->second;
        }
        return v[index][snap_id];
    }
};