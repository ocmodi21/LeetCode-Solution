#include <bits/stdc++.h>
using namespace std;

int bestClosingTime(string customers)
{
    int n = customers.size();
    int maxScore = 0, score = 0, bestHour = -1;
    for (int i = 0; i < n; i++)
    {
        score += (customers[i] == 'Y') ? 1 : -1;
        if (score > maxScore)
        {
            maxScore = score;
            bestHour = i;
        }
    }
    return bestHour + 1;
}