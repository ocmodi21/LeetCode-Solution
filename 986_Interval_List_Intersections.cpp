#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int list1 = 0;
    int list2 = 0;
    vector<vector<int>> ans;

    while (list1 < firstList.size() && list2 < secondList.size())
    {
        int start = max(firstList[list1][0], secondList[list2][0]);
        int end = min(firstList[list1][1], secondList[list2][1]);
        if (start <= end)
        {
            vector<int> temp(2, 0);
            temp[0] = start;
            temp[1] = end;
            ans.push_back(temp);
        }

        if (firstList[list1][1] >= secondList[list2][1])
            list2++;
        else
            list1++;
    }
    return ans;
}