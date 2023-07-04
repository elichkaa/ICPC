#include <bits/stdc++.h>
using namespace std;

const int64_t INF = INT32_MAX;
int64_t hc;
vector<bool> hasHideout;

bool bfs(int64_t source, int64_t destination, int64_t n, vector<int64_t> &parent, vector<vector<int64_t>> &residual)
{
    vector<bool> visited(n + 1, false);
    queue<int64_t> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int64_t current = q.front();
        q.pop();

        for (int64_t v = 1; v <= n; v++)
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

int64_t ff(int64_t source, int64_t target, int64_t n, vector<vector<int64_t>> &graph)
{
    vector<vector<int64_t>> residual(graph);

    vector<int64_t> parent(n + 1, -1);
    int64_t max_flow = 0;
    while (true)
    {
        vector<int64_t> parent(n + 1, -1);
        if (!bfs(source, target, n, parent, residual))
            break;

        int64_t path_flow = INF;
        int64_t v = target;
        while (v != source)
        {
            int64_t u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
            v = u;
        }

        v = target;
        while (v != source)
        {
            int64_t u = parent[v];
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
    int64_t n, m, h;
    cin >> n >> m >> h >> hc;
    hasHideout.resize(n);
    for (int64_t i = 0; i < h; i++)
    {
        int64_t ind;
        cin >> ind;
        hasHideout[ind - 1] = true;
    }
    vector<vector<int64_t>> graph(n + 2, vector<int64_t>(n + 2, 0));
    int64_t hideoutNode = n + 1;
    for (int64_t i = 0; i < m; i++)
    {
        int64_t u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] += capacity;
        graph[v][u] += capacity;
    }
    for (int64_t i = 0; i < n; i++)
    {
        if (hasHideout[i])
        {
            graph[i + 1][hideoutNode] += hc;
            graph[hideoutNode][i + 1] += hc;
        }
    }

    int64_t maxFlow = ff(1, n + 1, n + 1, graph);
    cout << maxFlow << endl;
    return 0;
}
