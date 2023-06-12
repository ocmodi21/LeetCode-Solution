#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> &v)
{
    vector<string> d;
    if (v.size() == 0)
        return d;

    int start, end;
    start = end = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1] + 1)
        {
            end++;
        }
        else
        {
            string s = "";
            if (start != end)
            {
                s += to_string(start) + "->" + to_string(end);
            }
            else
            {
                s += to_string(start);
            }
            d.push_back(s);
            start = end = v[i];
        }
    }
    string s = "";
    if (start != end)
    {
        s += to_string(start) + "->" + to_string(end);
    }
    else
    {
        s += to_string(start);
    }
    d.push_back(s);
    return d;
}