#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string nums, int k)
{
    int i = 0, j = 0, ans1 = 0;
    int tCount = 0;

    while (j < nums.size())
    {
        if (nums[j] == 'T')
            tCount++;
        if (tCount <= k)
        {
            ans1 = max(ans1, j - i + 1);
            j++;
        }
        else if (tCount > k)
        {
            while (tCount > k)
            {
                if (nums[i] == 'T')
                {
                    tCount--;
                }
                i++;
            }
            j++;
        }
    }

    i = 0, j = 0;
    int ans2 = 0;
    int fCount = 0;

    while (j < nums.size())
    {
        if (nums[j] == 'F')
            fCount++;
        if (fCount <= k)
        {
            ans2 = max(ans2, j - i + 1);
            j++;
        }
        else if (fCount > k)
        {
            while (fCount > k)
            {
                if (nums[i] == 'F')
                {
                    fCount--;
                }
                i++;
            }
            j++;
        }
    }
    return max(ans1, ans2);
}