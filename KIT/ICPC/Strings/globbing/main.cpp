#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string p;
        string t;
        getline(cin, p);
        getline(cin, t);
        bool ans = false;
        int pos = p.find('*');
        int pos2 = p.find('+');
        if (pos != string::npos)
        {
            string before = t.substr(0, pos);
            if ((int)t.length() - (int)before.length() < 0)
            {
                ans = false;
            }
            else
            {
                string after = t.substr(t.length() - before.length(), t.length());
                ans = before.length() + after.length() <= t.length() && before == p.substr(0, pos) && after == p.substr(pos + 1, p.length());
            }
        }
        else if (pos2 != string::npos)
        {
            string before = t.substr(0, pos2);
            if ((int)t.length() - (int)before.length() < 0)
            {
                ans = false;
            }
            else
            {
                string after = t.substr(t.length() - (p.length() - pos2 - 1), t.length());
                ans = before.length() + after.length() < t.length() && before == p.substr(0, pos2) && after == p.substr(pos2 + 1, p.length());
            }
        }
        else
        {
            ans = p == t;
        }
        if (ans == true)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}