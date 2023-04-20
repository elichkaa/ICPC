#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct comp
{
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) const
    {
        double leftCos = l.second * r.first;
        double rightCos = r.second * l.first;
        if (leftCos == rightCos)
        {
            return l.first < r.first;
        }
        return leftCos > rightCos;
    }
};

int main()
{
    string n;
    int x, y;
    map<pair<int, int>, string, comp> map;
    while (cin >> n >> x >> y)
    {
        map.insert(make_pair(make_pair(x, y), n));
    }
    for (auto const &s : map)
        cout << s.second << endl;
    return 0;
}
