#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'000'007;

int64_t countPaths(int n, int m, const vector<string> &grid)
{
    vector<vector<int64_t>> P(m, vector<int64_t>(n, 0));
    if (grid[0][0] == '*')
    {
        return 0;
    }

    P[0][0] = 1;

    for (int i = 1; i < m; ++i)
    {
        if (grid[i][0] == '*')
        {
            break;
        }
        P[i][0] = 1;
    }
    for (int j = 1; j < n; ++j)
    {
        if (grid[0][j] == '*')
        {
            break;
        }
        P[0][j] = 1;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (grid[i][j] == '.')
            {
                P[i][j] = (P[i - 1][j] + P[i][j - 1]) % MOD;
            }
        }
    }
    return P[m - 1][n - 1];
}

int main()
{
    int64_t n, m;
    cin >> n >> m;
    vector<string> grid(m);
    for (int64_t i = 0; i < m; ++i)
    {
        cin >> grid[i];
    }
    int64_t result = countPaths(n, m, grid);
    cout << result << endl;

    return 0;
}
