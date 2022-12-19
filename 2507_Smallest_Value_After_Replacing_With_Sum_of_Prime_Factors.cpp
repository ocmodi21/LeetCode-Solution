#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}
int smallestValue(int n)
{
    if (isPrime(n))
        return n;
    int sum = 0, N = n;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            sum += i;
        }
    }
    if (sum == N)
        return N;
    return smallestValue(sum);
}