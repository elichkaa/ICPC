#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    int64_t n, b, h, w;
    cin >> n >> b >> h >> w;
    int64_t ans = INT64_MAX;
    for (int i = 0; i < h; i++)
    {
        int64_t p;
        cin >> p;
        for (int j = 0; j < w; j++)
        {
            int64_t beds;
            cin >> beds;
            if (beds >= n)
            {
                int64_t calc = n * p;
                if (calc <= b)
                {
                    ans = min(ans, calc);
                }
            }
        }
    }
    if (ans == INT64_MAX)
    {
        cout << "stay home" << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}