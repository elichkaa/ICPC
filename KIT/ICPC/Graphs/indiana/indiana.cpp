#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int64_t n, h;
    cin >> n >> h;
    vector<vector<int>> adjList(n);
    for (int64_t i = 0; i < h; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }

    return 0;
}