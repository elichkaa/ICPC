#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        vector<char> v;
        int64_t black = 0;
        int64_t white = 0;
        int64_t b;
        cin >> b;
        for (int64_t j = 0; j < b; j++)
        {
            char a;
            cin >> a;
            v.push_back(a);
            if (a == 'B')
            {
                black++;
            }
            else if (a == 'W')
            {
                white++;
            }
        }
        if (black % 2 == 1 && white % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        char leading = white % 2 ? 'W' : 'B';

        vector<int64_t> index;
        for (int k = 0; k < v.size() - 1; k++)
        {
            if (v[k] == leading)
            {
                continue;
            }
            v[k] = leading;
            v[k + 1] = v[k + 1] == 'W' ? 'B' : 'W';
            index.push_back(k);
        }
        cout << "YES" << endl;
        cout << index.size() << endl;
        for (int i = 0; i < index.size(); i++)
        {
            cout << index[i] + 1 << " \n"[i == index.size() - 1];
        }
    }

    return 0;
}