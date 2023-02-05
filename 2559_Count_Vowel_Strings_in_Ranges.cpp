#include <bits/stdc++.h>
using namespace std;

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<string> vowel = words;
    vector<int> WordQueries;
    vector<int> ans;
    for (int i = 0; i < vowel.size(); i++)
    {
        string word = vowel[i];
        if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && (word[word.length() - 1] == 'a' || word[word.length() - 1] == 'e' || word[word.length() - 1] == 'i' || word[word.length() - 1] == 'o' || word[word.length() - 1] == 'u'))
        {
            if (i != 0)
                WordQueries.push_back(WordQueries[i - 1] + 1);
            else
                WordQueries.push_back(1);
        }
        else
        {
            vowel[i] = "";
            if (i != 0)
                WordQueries.push_back(WordQueries[i - 1]);
            else
                WordQueries.push_back(0);
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int firstWord, lastWord;
        if (queries[i][0] == 0)
            firstWord = 0;
        else
            firstWord = WordQueries[queries[i][0] - 1];
        lastWord = WordQueries[queries[i][1]];

        ans.push_back(lastWord - firstWord);
    }
    return ans;
}