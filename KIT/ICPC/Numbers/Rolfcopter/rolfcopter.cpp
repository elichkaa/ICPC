#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        if ((n * m) % 4 != 0)
        {
            cout << "WIN" << endl;
        }
        else
        {
            cout << "GTFO" << endl;
        }
    }

    return 0;
}