#include <bits/stdc++.h>
using namespace std;

long long minimumPossibleSum(int n, int target)
{
    unordered_set<int> st;
    long long sum = 0;
    long long i = 1;

    while (st.size() != n)
    {
        if (st.find(target - i) == st.end())
        {
            st.insert(i);
            sum += i;
        }
        i++;
    }
    return sum;
}