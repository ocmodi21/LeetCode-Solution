#include <bits/stdc++.h>
using namespace std;

long long smallestNumber(long long num)
{
    if (num == 0)
        return 0;
    long long smallestNumber;
    string numStr = to_string(num);

    if (numStr[0] == '-')
    {
        sort(numStr.begin() + 1, numStr.end());
        reverse(numStr.begin() + 1, numStr.end());
        smallestNumber = stoll(numStr);
    }
    else
    {
        sort(numStr.begin(), numStr.end());
        int zeroInd = 0;
        while (numStr[zeroInd] == '0')
            zeroInd++;
        swap(numStr[zeroInd], numStr[0]);
        smallestNumber = stoll(numStr);
    }
    return smallestNumber;
}