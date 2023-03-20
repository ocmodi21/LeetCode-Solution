#include <bits/stdc++.h>
using namespace std;

vector<int> evenOddBit(int n)
{
    vector<int> binaryNum(32);

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    int even = 0, odd = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        if (j % 2 == 0)
        {
            if (binaryNum[j] == 1)
                even++;
        }
        else
        {
            if (binaryNum[j] == 1)
                odd++;
        }
    }
    return {even, odd};
}