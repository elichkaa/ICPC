#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, c;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x >> c;
        int arr[c];
        int dp[c];
        for (int j = 0; j < c; j++)
        {
            cin >> arr[j];
            dp[j] = 1;
        }
        for (int i = 1; i < c; i++)
        {
            int m = INT16_MAX;
            for (int j = 1; j < c; j++)
            {
                m = min(m, x - arr[j - 1]);
            }
            dp[i] = m;
        }
        cout << dp[c - 1] << endl;
    }

    return 0;
}