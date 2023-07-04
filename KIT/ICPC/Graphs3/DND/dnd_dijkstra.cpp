#include <bits/stdc++.h>

using namespace std;

typedef pair<int64_t, int64_t> pp;
const int64_t INF = numeric_limits<int64_t>::max();

struct edge
{
    int32_t from, to;
    int64_t weight;
};

vector<vector<edge>> graph;
int64_t n;

vector<int64_t> calc(int64_t start)
{
    priority_queue<pp, vector<pp>, greater<pp>> q;
    q.push(make_pair(0, start));
    vector<int64_t> dist(n, INF);
    dist[start] = 0;
    while (!q.empty())
    {
        pp t = q.top();
        q.pop();

        if (t.first > dist[t.second])
            continue;

        for (const auto &e : graph[t.second])
        {
            if (t.first + e.weight < dist[e.to])
            {
                dist[e.to] = t.first + e.weight;
                q.emplace(make_pair(dist[e.to], e.to));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n;
    vector<pair<int64_t, int64_t>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    int m, a, b;
    cin >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;

        int64_t swords = (p[a].first - p[b].first) * (p[a].first - p[b].first);
        int64_t sorcery = (p[a].second - p[b].second) * (p[a].second - p[b].second);
        graph[a].emplace_back(edge{a, b, swords + sorcery});
        graph[b].emplace_back(edge{b, a, swords + sorcery});
    }

    vector<vector<int64_t>> costs(n);
    for (int i = 0; i < n; i++)
    {
        costs[i] = calc(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        b--;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        if (costs[a][b] == INF)
        {
            cout << "BRIBE DM WITH FOOD" << endl;
        }
        else
        {
            cout << costs[a][b] << endl;
        }
    }

    return 0;
}
