#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << "? insert 3" << endl;
    cout << "? insert 2" << endl;
    cout << "? insert 2" << endl;
    cout << "? insert 4" << endl;
    cout << "? insert 5" << endl;
    cout << "? remove" << endl;
    int ans;
    cin >> ans;
    if (ans == 3)
    {
        cout << "! queue" << endl;
    }
    else if (ans == 2)
    {
        cout << "? remove" << endl;
        cin >> ans;
        if (ans == 2)
        {
            cout << "! pq" << endl;
        }
        else
        {
            cout << "! set" << endl;
        }
    }
    else
    {
        cout << "! stack" << endl;
    }

    return 0;
}