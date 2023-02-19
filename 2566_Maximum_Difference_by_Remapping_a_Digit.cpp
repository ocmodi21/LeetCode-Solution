#include <bits/stdc++.h>
using namespace std;

int minMaxDifference(int num)
{
    string temp1 = to_string(num);
    string temp2 = to_string(num);
    char x = temp1[0], y = temp2[0];
    for (int i = 0; i < temp1.size(); i++)
    {
        if (temp1[i] != '9')
        {
            x = temp1[i];
            break;
        }
    }
    for (int i = 0; i < temp1.size(); i++)
    {
        if (temp1[i] == x)
            temp1[i] = '9';
    }
    for (int i = 0; i < temp2.size(); i++)
    {
        if (temp2[i] == y)
            temp2[i] = '0';
    }
    return stoi(temp1) - stoi(temp2);
}
