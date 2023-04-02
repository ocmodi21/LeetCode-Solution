#include <bits/stdc++.h>
using namespace std;

int findTheLongestBalancedSubstring(string s)
{
    int zero = 0, ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i;
        while (j < s.length() && s[j] == '0')
        {
            zero++;
            j++;
        }
        while (j < s.length() && s[j] == '1')
        {
            if (zero > 0)
            {
                zero--;
                j++;
            }
            else
                break;
        }
        if (zero == 0)
            ans = max(ans, j - i);
        else
            zero = 0;
    }
    if (ans % 2 != 0)
        ans = ans + 1;
    return ans;
}