#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int n = 8;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> optCut(n, 0);
    optCut[0] = prices[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > i / 2; j--)
        {
            int first = i - j;
            int second = j - 1;
            optCut[i] = max(max(optCut[i], prices[i]), optCut[i - j] + prices[j - 1]);
        }
    }

    cout << optCut[7] << endl;
    return 0;
}