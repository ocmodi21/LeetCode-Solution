#include <bits/stdc++.h>
using namespace std;

string toString(int num)
{
    string ans;
    int div = 1, mod = 10;
    while (num / div)
    {
        int curr = num % mod;
        curr = curr / div;
        ans = char('0' + curr) + ans;
        div *= 10;
        mod *= 10;
    }
    return ans;
}
int compress(vector<char> &chars)
{
    int n = chars.size();
    int last_ind = 0;

    for (int i = 0; i < n; i++)
    {
        int curr_freq = 1;
        char curr_char = chars[i];
        while (i < n - 1 && chars[i + 1] == chars[i])
        {
            i++;
            curr_freq++;
        }
        chars[last_ind++] = curr_char;
        if (curr_freq > 1)
        {
            string to_str = toString(curr_freq);
            for (auto &ch : to_str)
            {
                chars[last_ind++] = ch;
            }
        }
    }
    return last_ind;
}