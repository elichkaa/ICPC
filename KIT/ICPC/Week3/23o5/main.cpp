#include <bits/stdc++.h>

using namespace std;

bool backtrack(vector<int32_t> &numbers, int32_t idx, int32_t cur)
{
    if (idx == 5)
    {
        return cur == 23;
    }
    return backtrack(numbers, idx + 1, cur * numbers[idx]) || backtrack(numbers, idx + 1, cur + numbers[idx]) || backtrack(numbers, idx + 1, cur - numbers[idx]);
}

void solve(vector<int32_t> v)
{
    sort(v.begin(), v.end());
    do
    {
        if (backtrack(v, 1, v[0]))
        {
            cout << "Possible" << endl;
            return;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "Impossible" << endl;
}

int main()
{
    vector<int32_t> v = vector<int32_t>();
    int a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        {
            return 0;
        }
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        solve(v);
        v.clear();
    }
    return 0;
}