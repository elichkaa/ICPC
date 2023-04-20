#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

void operate(string &s, int num)
{
    if (num == 1)
    {
        if (s == "")
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    else if (num == 2)
    {
        cout << s.size() << endl;
    }
    else if (num == 3)
    {
        int pos;
        cin >> pos;
        s.erase(s.begin() + pos - 1);
    }
    else if (num == 4)
    {
        int pos;
        string i;
        cin >> pos >> i;
        s.insert(pos - 1, i);
    }
    else if (num == 5)
    {
        int f, e;
        cin >> f >> e;
        swap(s[f - 1], s[e - 1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        string c;
        cin >> c;
        for (int j = 0; j < b; j++)
        {
            int d;
            cin >> d;
            operate(c, d);
        }
    }
    return 0;
}