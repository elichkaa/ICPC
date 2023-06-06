#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    int64_t a, b, c;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (c == 1 || c == 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            if ((a % c) + (b % c) == 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}