#include <iostream>
#include <vector>

using namespace std;

const int mod = 1020847;
const int maxN = 2000;
vector<vector<int64_t>> dp(maxN + 1, vector<int64_t>(maxN + 1, -1));

int64_t c(int n, int p)
{
    if (p == 1 || p == n)
    {
        return 1;
    }
    if (dp[n][p] != -1)
    {
        return dp[n][p];
    }
    int64_t result = (p * c(n - 1, p) + (n - p + 1) * c(n - 1, p - 1)) % mod;
    dp[n][p] = result;
    return result;
}

int main()
{
    int n, p;
    while (cin >> n >> p && n != 0 && p != 0)
    {
        int64_t ans = c(n, p);
        cout << ans << endl;
    }
    return 0;
}
