#include <bits/stdc++.h>

using namespace std;

vector<bool> bfs(const vector<vector<int>> &m, int start)
{
    vector<bool> visited(m.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        visited[current] = true;
        for (int n : m[current])
        {
            if (!visited[n])
            {
                q.push(n);
            }
        }
    }

    return visited;
}

int main()
{
    int64_t n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int64_t i = 0; i < m; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }
    vector<bool> v = bfs(adjList, 0);

    for (bool vis : v)
    {
        if (vis == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}