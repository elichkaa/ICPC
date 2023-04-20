/*
USACO 2022 US Open Contest, Bronze
Problem 2. Counting Liars
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
    int n = 0, num = 0, c = 0;
    cin >> n;
    char dir;
    vector<pair<int, char>> col;

    for (int i = 0; i < n; i++)
    {
        cin >> dir >> num;
        col.push_back({num, dir});
    }
    sort(col.begin(), col.end());

    vector<int> loc(col[col.size() - 1].first + 1);
    for (int i = 0; i < n; i++)
    {
        if (col[i].second == 'L')
        {
            for (int j = col[i].first; j >= 0; j--)
            {
                loc[j]++;
            }
        }
        else if (col[i].second == 'G')
        {
            for (int j = col[i].first; j < loc.size(); j++)
            {
                loc[j]++;
            }
        }
        if (!count(loc.begin(), loc.end(), i + 1))
        {
            c++;
        }
    }

    cout << c << endl;
    return 0;
}