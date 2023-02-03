#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int pattern = (numRows - 1) * 2;
    int j;
    string zigzag;
    for (int i = 0; i < numRows; i++)
    {
        j = i;
        while (j < s.length())
        {
            zigzag += s[j];
            if (i != 0 && i != numRows - 1)
            {
                int tempPattern = pattern - 2 * i;
                int index = j + tempPattern;
                if (index < s.length())
                    zigzag += s[index];
            }
            j += pattern;
        }
    }
    return zigzag;
}