#include <bits/stdc++.h>
using namespace std;

double angleClock(int hour, int minutes)
{
    if (hour == 12)
        hour = 0;
    double x = abs((60 * hour) - (11 * minutes));
    if (x / 2 <= 180)
        return (x / 2);
    else
        return 360 - (x / 2);
}