#include <bits/stdc++.h>

using namespace std;

void bernd(int i)
{
    if (i == 0)
    {
        cout << 1 << " ";
    }
    else
    {
        bernd(i / 2);
        cout << 1 << " ";
        bernd(i / 2);
        cout << 1 << " ";
        bernd(i / 2);
    }
}

int main()
{
    bernd(14);
    return 0;
}