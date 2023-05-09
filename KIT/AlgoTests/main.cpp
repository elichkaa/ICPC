#include <bits/stdc++.h>

using namespace std;
int64_t coins[10], best;

int64_t solve(int64_t sum)
{
    if (sum < 0)
    {
        return INT32_MAX;
    }
    if (sum == 0)
    {
        return 0;
    }
    best = INT32_MAX;
    for (int i = 0; i < 3; i++)
    {
        best = min(best, solve(sum - coins[i]) + 1);
    }
    return best;
}

int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> coins[i];
    }
    cout << solve(0) << endl;
    cout << solve(3) << endl;
    cout << solve(10) << endl;
    return 0;
}