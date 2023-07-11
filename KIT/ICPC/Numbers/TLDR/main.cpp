#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define N 880555

ll modExp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % N;
        b >>= 1;
        a = (a * a) % N;
    }
    return res;
}

ll modInverse(ll a)
{
    for (ll i = 1; i < N; i++)
    {
        if (((a % N) * (i % N)) % N == 1)
        {
            return i;
        }
    }
    return 0;
}

ll solve(ll num, ll inv)
{
    return (num - 1) * inv;
}

int main()
{
    int t;
    cin >> t;

    ll invFirst = modInverse(6);
    ll invSecond = modInverse(16);
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll first = modExp(7, n + 1);
        ll second = modExp(17, n * 2 + 1);
        ll firstSum = solve(first, invFirst) % N;
        ll secondSum = solve(second, invSecond) % N;
        ll sum = (firstSum * secondSum) % N;
        cout << sum << endl;
    }

    return 0;
}
