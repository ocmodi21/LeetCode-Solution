#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> res;
    unordered_map<string, int> m;
    for (int i = 0; i + 10 <= s.size(); i++)
    {
        string seq = s.substr(i, 10);
        if (m[seq] == 1)
            res.push_back(seq);
        m[seq]++;
    }
    return res;
}