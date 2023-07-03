#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int target, vector<int> &allPrimes)
{
    int l = 0, h = allPrimes.size() - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (allPrimes[mid] < target)
            l = mid + 1;
        else if (allPrimes[mid] > target)
            h = mid - 1;
        else if (allPrimes[mid] == target)
            return true;
    }
    return false;
}

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> allPrimes;
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            allPrimes.push_back(i);
    }
    return allPrimes;
}

vector<vector<int>> findPrimePairs(int n)
{
    vector<vector<int>> primePairs;
    vector<int> allPrimes = sieve(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < allPrimes.size(); i++)
    {
        int num1 = allPrimes[i];
        int num2 = n - allPrimes[i];

        if (!visited[num1] && !visited[num2] && binarySearch(num2, allPrimes))
        {
            primePairs.push_back({num1, num2});
            visited[num1] = true;
            visited[num2] = true;
        }
    }
    return primePairs;
}