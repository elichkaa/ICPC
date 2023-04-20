/*
USACO 2019 December Contest, Bronze
Problem 1. Cow Gymnastics
id: chrollo
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    ofstream fout("gymnastics.out");
    ifstream fin("gymnastics.in");
    int k, n;
    fin >> k >> n;
    int arr[10][20];
    int c = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> arr[i][j];
        }
    }
    bool works = true;
    bool works1 = true;
    map<int, int> mp;
    int ans = 0;
    //cols from second on
    for (int i = 1; i < n; i++)
    {
        //cols from third on
        for (int y = i + 1; y <= n; y++)
        {
            works = true;
            works1 = true;
            //rows
            for (int j = 0; j < k; j++)
            {
                //cols
                for (int x = 0; x < n; x++)
                {
                    if (arr[j][x] == i)
                    {
                        mp[i] = x;
                    }
                    else if (arr[j][x] == y)
                    {
                        mp[y] = x;
                    }
                }
                if (mp[i] < mp[y])
                {
                    works = false;
                }
                else if (mp[y] < mp[i])
                {
                    works1 = false;
                }
            }
            if (works)
            {
                ans++;
            }
            if (works1)
            {
                ans++;
            }
        }
    }

    fout << ans << endl;
    return 0;
}