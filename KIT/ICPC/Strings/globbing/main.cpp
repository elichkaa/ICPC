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
        if (pos != string::npos && pos2 != string::npos)
        {
            ans = p == t;
        }
        else
        {
            if (pos != string::npos)
            {
                string before = t.substr(0, pos);
                if ((int)t.length() - (int)before.length() < (int)p.length() - pos - 1)
                {
                    ans = false;
                }
                else
                {
                    string after = t.substr(t.length() - (p.length() - pos - 1));
                    ans = before == p.substr(0, pos) && after == p.substr(pos + 1, p.length() - pos - 1);
                }
            }
            else
            {
                string before = t.substr(0, pos2);
                if ((int)t.length() - (int)before.length() < (int)p.length() - pos2 - 1)
                {
                    ans = false;
                }
                else
                {
                    string after = t.substr(t.length() - (p.length() - pos2 - 1));
                    ans = before == p.substr(0, pos2) && after == p.substr(pos2 + 1, p.length() - pos2 - 1);
                }
            }
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
