#include <bits/stdc++.h>

using namespace std;

int apply(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
    return 0;
}

bool solve(vector<int> &numbers, int result, int mask)
{
    if (mask == (1 << 5) - 1 || result > 173 || result < -77)
    {
        return result == 23;
    }
    bool possible = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];
        if ((mask & (1 << i)) == 0)
        {
            possible |= solve(numbers, apply(result, num, '+'), mask | (1 << i));
            possible |= solve(numbers, apply(result, num, '-'), mask | (1 << i));
            possible |= solve(numbers, apply(result, num, '*'), mask | (1 << i));
        }
    }
    return possible;
}

int main()
{
    int a, b, c, d, e;
    vector<int> v;
    while (cin >> a >> b >> c >> d >> e)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        {
            return 0;
        }
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        sort(v.begin(), v.end());
        bool possible = false;
        do
        {
            possible |= solve(v, v[0], 1);
        } while (next_permutation(v.begin(), v.end()) && !possible);
        cout << (possible ? "Possible" : "Impossible") << endl;
        v.clear();
    }

    return 0;
}