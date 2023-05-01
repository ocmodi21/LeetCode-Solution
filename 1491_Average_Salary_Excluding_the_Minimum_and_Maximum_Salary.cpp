#include <bits/stdc++.h>
using namespace std;

double average(vector<int> &salary)
{
    sort(salary.begin(), salary.end());
    double avgSalary = 0;
    for (int i = 1; i < salary.size() - 1; i++)
        avgSalary += salary[i];
    return avgSalary / (salary.size() - 2);
}