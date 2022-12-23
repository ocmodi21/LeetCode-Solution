#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int maxArea = 0;
    while (i < j)
    {
        maxArea = max(min(height[i], height[j]) * (j - i), maxArea);
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return maxArea;
}