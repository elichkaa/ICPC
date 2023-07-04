#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>

#define MAXN 1000
#define INF 2147483646

using namespace std;

int capacity[MAXN][MAXN];
int flowPassed[MAXN][MAXN];
int path_flow[MAXN] = {0};
vector<int> graph[MAXN];
vector<int> parent(MAXN, -1);

bool bfs(int s, int t)
{
    queue<int> q;
    parent[s] = -2;
    q.push(s);
    path_flow[s] = INF;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (parent[v] == -1)
            {
                if (capacity[u][v] - flowPassed[u][v] > 0)
                {
                    parent[v] = u;
                    path_flow[v] = min(path_flow[u], capacity[v][u] - flowPassed[v][u]);
                    if (v == u)
                        return path_flow[v];
                    q.push(v);
                }
            }
        }
    }
    return 0;
}

int max_flow(int source, int sink)
{
    int maxFlow = 0;
    while (1)
    {
        int flow = bfs(source, sink);
        if (flow == 0)
            break;
        int u = sink;
        maxFlow += flow;
        while (u != source)
        {
            int v = parent[u];
            flowPassed[v][u] += flow;
            flowPassed[u][v] -= flow;
        }
    }
    return maxFlow;
}

int main()
{
    int n, maxJump;
    cin >> n >> maxJump;
    vector<int> parent(n + 1, -1);
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        capacity[i - 1][i] = a;
        graph[i - 1].push_back(i);
        graph[i].push_back(i - 1);
    }
    int maxFlow = max_flow(0, n - 1);

    cout << maxFlow << endl;

    return 0;
}