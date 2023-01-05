#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime[i])
            count++;
    }
    return count;
}