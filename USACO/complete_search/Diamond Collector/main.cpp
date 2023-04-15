/*
USACO 2016 US Open Contest, Bronze
Problem 1. Diamond Collector
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
    ofstream fout("diamond.out");
    ifstream fin("diamond.in");
    int n, k;
    fin >> n >> k;
    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        int num;
        fin >> num;
        d.push_back(num);
    }
    sort(d.begin(), d.end());
    int counter = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i] <= d[j] && d[j] - d[i] <= k)
            {
                counter++;
            }
        }
        res = max(counter, res);
        counter = 0;
    }

    fout << res << endl;
    return 0;
}