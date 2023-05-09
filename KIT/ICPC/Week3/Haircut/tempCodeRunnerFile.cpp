#include <bits/stdc++.h>
using namespace std;

int b, n;
int64_t v[1005], t;

int64_t clients(int64_t t)
{
    int64_t res = 0;
    for (int64_t i = 0; i < b; i++)
    {
        res += t / v[i] + 1;
    }
    return res;
}

int main()
{
    cin >> n;
    int caseNum = 1;
    while (n--)
    {
        cin >> b >> t;
        for (int64_t i = 0; i < b; i++)
        {
            cin >> v[i];
        }
        int64_t lo = -1, hi = 100005 * t;
        while (lo + 1 < hi)
        {
            int64_t mid = (lo + hi) / 2;
            if (clients(mid) < t)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        int before = clients(hi - 1);
        int after = t - before - 1;
        for (int64_t j = 0; j < b; j++)
        {
            if (hi % v[j] == 0)
            {
                after--;
                if (after == 0)
                {
                    cout << "Case #" << caseNum++ << ": " << j + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}