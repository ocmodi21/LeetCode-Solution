#include <bits/stdc++.h>
using namespace std;

vector<int> replaceNonCoprimes(vector<int> &a)
{
    stack<int> st;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int current = a[i];
        int gcd, LCM, top;
        while (!st.empty())
        {

            int gcd = __gcd(current, st.top());
            if (gcd > 1)
            {
                top = st.top();
                st.pop();
                LCM = (current / gcd) * top;
                current = LCM;
            }
            else
                break;
        }
        st.push(current);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}