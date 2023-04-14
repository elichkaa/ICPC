/*
   ID: reynamommy/codeforces
   TASK: milk2
   LANG: C++
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
    int n, p;
    cin >> n;
    vector<int> xPoints;
    vector<int> yPoints;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        xPoints.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        yPoints.push_back(p);
    }
    int cur = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cur = pow(xPoints[i] - xPoints[j], 2) + pow(yPoints[i] - yPoints[j], 2);
            mx = max(mx, cur);
        }
    }
    cout << mx << endl;
    return 0;
}