#include <bits/stdc++.h>
using namespace std;

// Approch-1
int distinctIntegers(int n)
{
    if (n == 1)
        return 1;
    set<int> st;
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            if (i % j == 1)
                st.insert(j);
        }
    }
    return st.size();
}

// Approch-2
int distinctIntegers(int n)
{
    if (n == 1)
        return 1;
    return n - 1;
}