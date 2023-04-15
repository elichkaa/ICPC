/*
USACO 2016 February Contest, Bronze
Problem 1. Milk Pails
id: chrollo
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ofstream fout("pails.out");
    ifstream fin("pails.in");
    int x, y, m;
    int cur = 0, mx = 0;
    fin >> x >> y >> m;
    int size = m / x;
    vector<int> f;
    vector<int> s;
    for (int i = 0; i < size; i++)
    {
        f.push_back(x);
        s.push_back(y);
    }

    for (int i = 0; i <= size; i++)
    {
        cur += i * x;
        while (cur + y <= m)
        {
            cur += y;
        }

        mx = max(mx, cur);
        cur = 0;
    }
    fout << mx << endl;
    return 0;
}