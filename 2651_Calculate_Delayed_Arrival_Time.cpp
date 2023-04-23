#include <bits/stdc++.h>
using namespace std;

int findDelayedArrivalTime(int arrivalTime, int delayedTime)
{
    return (arrivalTime + delayedTime) % 24;
}