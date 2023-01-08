#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string categorizeBox(int length, int width, int height, int mass)
{
    bool a = length >= 10000 || width >= 10000 || height >= 10000 || mass >= 10000 || (ll)length * width * height >= 1000000000;
    bool b = mass >= 100;
    if (a && b)
        return "Both";
    if (a)
        return "Bulky";
    if (b)
        return "Heavy";
    return "Neither";
}