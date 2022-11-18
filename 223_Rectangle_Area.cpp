#include <bits/stdc++.h>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int areaA = (ax2 - ax1) * (ay2 - ay1);
    int areaB = (bx2 - bx1) * (by2 - by1);

    int overLap = 0;

    int xOverLap = min(ax2, bx2) - max(ax1, bx1);
    int yOverLap = min(ay2, by2) - max(ay1, by1);
    if (xOverLap > 0 && yOverLap > 0)
        overLap = xOverLap * yOverLap;

    return areaA + areaB - overLap;
}