#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &str)
{
    int count = 0;
    for (int i = 0; i < str[0].length(); i++)
    {
        for (int j = 1; j < str.size(); j++)
        {
            if (str[j][i] < str[j - 1][i])
            {
                count++;
                break;
            }
        }
    }
    return count;
}