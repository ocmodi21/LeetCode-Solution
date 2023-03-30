#include <bits/stdc++.h>
using namespace std;

static bool cmp(string a, string b)
{
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> temp;
    for (auto it : nums)
        temp.push_back(to_string(it));

    string ans = "";
    sort(temp.begin(), temp.end(), cmp);
    if (temp[0] == "0")
        return "0";
    for (auto it : temp)
        ans += it;
    return ans;
}