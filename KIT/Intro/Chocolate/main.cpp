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
    int w, h;
    fin >> w >> h;
    fout << w * h - 1 << endl;
    return 0;
}