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
        a = (a * a) % N;
        b >>= 1;
    }
    return res;
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

ll sum_all_divisors_original(ll num)
{
    ll originalSum = 0;
    ll p = 2023;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            originalSum += i;
            if (i != num / i)
            {
                originalSum += num / i;
            }
        }
    }
    return originalSum;
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
        ll divisorsSum = sum_all_divisors(res);
        ll originalSum = sum_all_divisors(divisorsSum);
        cout << originalSum << endl;
    }

    return 0;
}
