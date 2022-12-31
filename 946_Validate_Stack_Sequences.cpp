#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int push = 0;
    int pop = 0;

    for (int i = 0; i < pushed.size(); i++)
    {
        pushed[push] = pushed[i];
        push++;

        while (push > 0 && pushed[push - 1] == popped[pop])
        {
            push--;
            pop++;
        }
    }
    return push == 0 ? true : false;
}