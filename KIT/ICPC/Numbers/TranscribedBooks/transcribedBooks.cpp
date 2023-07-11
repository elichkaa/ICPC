#include <bits/stdc++.h>

using namespace std;
typedef int64_t ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ci;
        cin >> ci;
        for (int j = 0; j < ci; j++)
        {
            for (int n = 0; n < 10; n++)
            {
                vector<vector<ll>> nums(ci, vector<ll>(10));
                cin >> nums[j][n];
                ll result = accumulate(nums.begin(), nums.end() - 1, 0);
            }
        }
    }

    return 0;
}