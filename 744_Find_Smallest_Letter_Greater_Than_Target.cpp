#include <bits/stdc++.h>
using namespace std;

// Approch-1
char nextGreatestLetter(vector<char> &letters, char target)
{
    for (int i = 0; i < letters.size(); i++)
    {
        if (letters[i] > target)
            return letters[i];
    }
    return letters[0];
}

// Approch-2
char nextGreatestLetter(vector<char> &letters, char target)
{
    int low = 0;
    int high = letters.size() - 1;
    char ans = letters[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// Approch-3
char nextGreatestLetter(vector<char> &letters, char target)
{
    auto it = upper_bound(letters.begin(), letters.end(), target);
    int index = it - letters.begin();
    return index == letters.size() ? letters[0] : letters[index];
}