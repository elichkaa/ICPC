#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int64_t k, s;
        cin >> k;
        set<int64_t> q;
        vector<int64_t> v;
        int64_t m = 0, size = 0;
        int ind = 0;
        for (int j = 0; j < k; j++)
        {
            cin >> s;
            if (q.count(s) > 0)
            {
                size = q.size();
                m = max(size, m);
                while (v[ind] != s)
                {
                    q.erase(v[ind]);
                    ind++;
                }
                q.erase(v[ind]);
                ind++;
                q.insert(s);
                v.push_back(s);
            }
            else
            {
                v.push_back(s);
                q.insert(s);
            }
        }
        size = q.size();
        m = max(size, m);
        cout << m << endl;
    }
    return 0;
}