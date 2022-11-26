#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string t = "";
    int flag = 0;
    int x = min(a.size(), b.size());

    int carry = 0;
    for (int i = 0; i < x; i++)
    {
        flag = 1;
        if ((a[i] == '0') && (b[i] == '0'))
        {
            if (carry == 0)
            {
                t.push_back('0');
            }
            else
            {
                t.push_back('1');
                carry = 0;
            }
        }
        if (((a[i] == '1') && (b[i] == '0')) || ((a[i] == '0') && (b[i] == '1')))
        {
            if (carry == 0)
            {
                t += '1';
            }
            else
            {
                t += '0';
            }
        }
        if ((a[i] == '1') && (b[i] == '1'))
        {
            if (carry == 0)
            {
                t += '0';
                carry = 1;
            }
            else
            {
                t += '1';
            }
        }
    }

    while (x < a.size())
    {
        if (carry == 0)
        {
            if (a[x] == '1')
            {
                t += '1';
            }
            else
            {
                t += '0';
            }
        }
        else
        {
            if (a[x] == '0')
            {
                t += '1';
                carry = 0;
            }
            else
            {
                t += '0';
            }
        }
        x++;
    }
    while (x < b.size())
    {
        if (carry == 0)
        {
            t += b[x];
        }
        else
        {
            if (b[x] == '0')
            {
                t += '1';
                carry = 0;
            }
            else
            {
                t += '0';
            }
        }
        x++;
    }

    if (carry == 1)
    {
        t += '1';
    }

    while (t[t.size() - 1] == '0')
        t.erase(t.end() - 1);
    reverse(t.begin(), t.end());
    return t;
}