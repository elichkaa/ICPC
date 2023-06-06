#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int64_t i = 0; i < s.size(); i++)
    {
        char a = s[i];
        string rest = s;
        int64_t pos = 0;
        int64_t c = count(s.begin(), s.end(), a);
        while (c--)
        {
            if (i < s.size() - 1 && a > rest.find(a) + 1)
            {
                pos = rest.find(a);
                rest = rest.substr(pos, s.length());
            }
            else
            {
                pos = rest.find(a);
                s.erase(pos, 1);
                rest.erase(pos, 1);
            }
        }
    }
    cout << s << endl;

    return 0;
}