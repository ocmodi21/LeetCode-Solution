#include <bits/stdc++.h>
using namespace std;

int passThePillow(int n, int time)
{
    int direction = 1;
    if ((time / (n - 1)) % 2 == 1)
        direction = -1;

    if (direction == 1)
        return 1 + (time % (n - 1));
    return n - (time % (n - 1));
}