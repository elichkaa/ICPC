#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int n;
    getline(cin, line);
    n = stoi(line);
    for (int i = 0; i < n; i++)
    {
        stack<int> s;
        int64_t sum = 0;
        int c = 0;
        getline(cin, line);
        for (char a : line)
        {
            if (a == '\\')
            {
                s.push(c);
            }
            else if (!s.empty())
            {
                if (a == '/')
                {
                    sum += c - s.top();
                    s.pop();
                }
            }
            c++;
        }
        cout << sum << endl;
    }

    return 0;
}