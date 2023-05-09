#include <bits/stdc++.h>
using namespace std;

int b, n;
int64_t v[10005], t;

int64_t clients(int64_t t)
{
    if (t < 0)
    {
        return 0;
    }

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
    while (n--)
    {
        cin >> b >> t;
        for (int64_t i = 0; i < b; i++)
        {
            cin >> v[i];
        }
        int64_t lo = -1, hi = 100'000'000'000'000'00L;
        while (lo + 1 < hi)
        {
            int64_t mid = (lo + hi) / 2;
            if (clients(mid) < t)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        int64_t before = t - clients(hi - 1);

        for (int64_t j = 0; j < b; j++)
        {
            if (hi % v[j] == 0)
            {
                before--;
                if (before == 0)
                {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}