#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &a)
{
    int product = 1;
    int maxProduct = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        product *= a[i];
        maxProduct = max(maxProduct, product);
        if (product == 0)
            product = 1;
    }

    product = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        product *= a[i];
        maxProduct = max(maxProduct, product);
        if (product == 0)
            product = 1;
    }
    return maxProduct;
}