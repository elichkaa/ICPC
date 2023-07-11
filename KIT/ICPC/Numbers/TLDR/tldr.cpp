#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define N 880555
#define md 880555

ll modExp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a);
        b >>= 1;
        a = (a * a);
    }
    return res % N;
}

ll sum_all_divisors(ll num)
{
    ll sum = 0;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i)
            {
                sum += num / i;
            }
        }
    }
    return sum;
}

ll sumAll(ll num, ll n)
{
    ll sq = sqrt(num);
    ll inv = modExp(2, N - 2);
    ll sum = 0;
    for (int i = 1; i <= sq; i++)
    {
        int x = (n / i - n / (i + 1)) % md;
        int r = n / i, l = n / (i + 1) + 1;
        sum = (sum + x * ((l + r) % md) % md * inv % md * i % md) % md;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll res = modExp(2023, n);
        ll sum = 0;
        ll sq = sqrt(n);
        ll inv = modExp(2, N - 2);
        for (ll i = 1; i <= sq; i++)
        {
            ll x = (n / i - n / (i + 1)) % N;
            ll r = n / i, l = n / (i + 1) + 1;
            sum = (sum + x * ((l + r) % N) % N * inv % N * i % N) % N;
        }
        for (ll i = 1; i <= n / (sq + 1); i++)
        {
            sum = (sum + n / i * i) % N;
        }
        cout << sum << endl;
    }

    return 0;
}
