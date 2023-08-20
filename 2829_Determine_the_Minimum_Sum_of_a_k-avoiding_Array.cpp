#include <bits/stdc++.h>
using namespace std;

int minimumSum(int n, int k)
{
    unordered_set<int> st;
    int sum = 0;
    int i = 1;

    while (st.size() != n)
    {
        if (st.find(k - i) == st.end())
        {
            st.insert(i);
            sum += i;
        }
        i++;
    }
    return sum;
}