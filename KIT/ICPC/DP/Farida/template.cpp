#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int64_t coins[100005];
    for (int64_t i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int64_t> dp(n);
    // first monster coins
    dp[0] = coins[0];
    if (n > 1)
    {
        // second monster, only take if its more than the first
        dp[1] = max(coins[0], coins[1]);
    }
    for (int64_t i = 2; i < n; i++)
    {
        // monsters from third to last
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }

    // max coins up to the last monster
    cout << dp[n - 1] << endl;

    return 0;
}