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
    ofstream fout("1.out");
    ifstream fin("1.in");
    int n, b, h, w;
    fin >> n >> b >> h >> w;
    int ans = INT_MAX;
    for (int i = 0; i < h; i++)
    {
        int p;
        fin >> p;
        for (int j = 0; j < w; j++)
        {
            int beds;
            fin >> beds;
            if (beds >= n)
            {
                int calc = beds * p;
                if (calc <= b)
                {
                    ans = min(ans, calc);
                }
            }
        }
    }
    if (ans == INT_MAX)
    {
        fout << "stay home" << endl;
        return 0;
    }
    
    fout << ans << endl;
    return 0;
}