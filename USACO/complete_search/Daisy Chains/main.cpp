/*
USACO 2020 December Contest, Bronze
Problem 2. Daisy Chains
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
    int n;
    cin >> n;
    vector<int> petals;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        petals.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            pairs.push_back({i, j});
        }
    }
    int c = 0;
    for (int i = 0; i < pairs.size(); i++)
    {
        double petalSum = 0;
        double size = pairs[i].second - pairs[i].first + 1;
        for (int j = 0; j < size; j++)
        {
            petalSum += petals[pairs[i].first + j];
        }
        double avg = petalSum / size;
        for (int j = 0; j < size; j++)
        {
            if (petals[pairs[i].first + j] == avg)
            {
                c++;
                break;
            }
        }
    }

    cout << c << endl;
    return 0;
}