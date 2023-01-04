#include <bits/stdc++.h>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int> &asteroids)
{
    sort(asteroids.begin(), asteroids.end());
    long long totalMass = mass;

    for (int i = 0; i < asteroids.size(); i++)
    {
        if (totalMass >= asteroids[i])
            totalMass += asteroids[i];
        else
            return 0;
    }
    return 1;
}