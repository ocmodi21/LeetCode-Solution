#include <bits/stdc++.h>
using namespace std;

vector<int> closestPrimes(int left, int right)
{
    vector<bool> isPrime(1e6 + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 1e6; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < 1e6; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> ans;
    vector<int> temp;
    int diff = 1e9;
    for (int i = left; i <= right; i++)
    {
        if (isPrime[i])
        {
            temp.push_back(i);
            if (temp.size() == 2)
            {
                if (temp[1] - temp[0] < diff)
                {
                    diff = temp[1] - temp[0];
                    ans = temp;
                }
                temp.clear();
                temp.push_back(i);
            }
        }
    }
    if (ans.size() == 0)
        return {-1, -1};
    return ans;
}