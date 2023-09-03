#include <bits/stdc++.h>
using namespace std;

int countSymmetricIntegers(int low, int high)
{
    int i = low, counter = 0;
    while (i <= high)
    {
        string num = to_string(i);
        int size = num.length();
        if (size % 2 == 0)
        {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < size / 2; j++)
                sum1 += num[j] - '0';
            for (int j = size / 2; j < size; j++)
                sum2 += num[j] - '0';

            if (sum1 == sum2 && sum1 != 0 && sum2 != 0)
                counter++;
        }
        i++;
    }

    return counter;
}