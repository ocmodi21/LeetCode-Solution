#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string s)
{
    set<char> st(s.begin(), s.end());
    if (st.size() == 26)
        return 1;
    else
        return 0;
}