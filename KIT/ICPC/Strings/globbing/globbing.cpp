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
            for (int prefixLen = 0; prefixLen <= t.length(); prefixLen++)
            {
                string prefix = t.substr(0, prefixLen);
                string suffix = t.substr(prefixLen);
                string patternPrefix = p.substr(0, pos);
                string patternSuffix = p.substr(pos + 1);

                if (prefix == patternPrefix && suffix == patternSuffix)
                {
                    ans = true;
                    break;
                }
            }
        }
        else if (pos2 != string::npos)
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
        else
        {
            ans = p == t;
        }

        if (ans)
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
