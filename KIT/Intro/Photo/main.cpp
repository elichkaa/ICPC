#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct comp
{
    bool operator()(const pair<double, double> &l, const pair<double, double> &r)
    {
        double leftCos = l.second / l.first;
        double rightCos = r.second / r.first;
        if (leftCos == rightCos)
        {
            return l.first < r.first;
        }
        return leftCos > rightCos;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    ofstream fout("1.out");
    ifstream fin("1.in");
    string n;
    double x, y;
    map<pair<double, double>, string, comp> map;
    while (fin >> n >> x >> y)
    {
        map.insert(make_pair(make_pair(x, y), n));
    }
    for (auto const &s : map)
        fout << s.second << endl;
    return 0;
}
