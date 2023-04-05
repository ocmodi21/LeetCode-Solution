#include <bits/stdc++.h>
using namespace std;

int partitionString(string s)
{
    unordered_set<char> st;
    int counter = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.find(s[i]) != st.end())
        {
            counter++;
            st.clear();
        }
        st.insert(s[i]);
    }
    return counter;
}