#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

bool bfs(int source, int destination, int n, vector<int>& parent, vector<vector<int>>& residual)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && residual[current][v] > 0)
            {
                q.push(v);
                parent[v] = current;
                visited[v] = true;
            }
        }
    }

    return visited[destination];
}

int ff(int source, int target, int n, vector<vector<int>>& graph)
{
    vector<vector<int>> residual(graph);

    vector<int> parent(n + 1, -1);
    int max_flow = 0;
    while (true)
    {
        vector<int> parent(n + 1, -1);
        if (!bfs(source, target, n, parent, residual))
            break;

        int path_flow = INF;
        int v = target;
        while (v != source)
        {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
            v = u;
        }

        v = target;
        while (v != source)
        {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
            v = u;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] += capacity;
        graph[v][u] += capacity;
    }

    int maxFlow = ff(1, 2, n, graph);
    cout << maxFlow << endl;

    return 0;
}
