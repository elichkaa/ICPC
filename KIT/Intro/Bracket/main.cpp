#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
ofstream fout("1.out");
ifstream fin("1.in");

int checkBracket(string &s)
{
    stack<char> v;
    int min = 0;
    for (auto &a : s)
    {
        if (a == '(' || a == '{' || a == '[')
        {
            v.push(a);
        }
        else
        {
            if (v.empty())
            {
                min++;
            }
            else
            {
                if (v.top() == '{' && a == '}' || v.top() == '(' && a == ')' || v.top() == '[' && a == ']')
                {
                    v.pop();
                }
                else
                {
                    min++;
                }
            }
        }
    }
    return min;
}

void operate(string &s, int num)
{
    if (num == 1)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (rev == s && checkBracket(s) == 0)
        {
            fout << "yes" << endl;
        }
        else
        {
            fout << "no" << endl;
        }
    }
    else if (num == 2)
    {
        fout << checkBracket(s) << endl;
    }
    else if (num == 3)
    {
        int pos;
        fin >> pos;
        s.erase(s.begin() + pos - 1);
    }
    else if (num == 4)
    {
        int pos;
        string i;
        fin >> pos >> i;
        s.insert(pos, i);
    }
    else if (num == 5)
    {
        int f, e;
        fin >> f >> e;
        swap(s[f - 1], s[e - 1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        string c;
        fin >> c;
        for (int j = 0; j < b; j++)
        {
            int d;
            fin >> d;
            operate(c, d);
        }
    }
    return 0;
}