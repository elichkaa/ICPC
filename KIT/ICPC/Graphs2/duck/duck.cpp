#include <bits/stdc++.h>

using namespace std;

int64_t n, m;
vector<int64_t> parent, height, costs;

struct edge
{
    int64_t from, to;
    int64_t cost;
};

struct isSmaller
{
    bool operator()(const edge &a, const edge &b)
    {
        return a.cost < b.cost;
    }
};

int64_t find(int64_t a)
{
    if (a != parent[a])
        parent[a] = find(parent[a]);
    return parent[a];
}

void unite(int64_t a, int64_t b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (height[a] < height[b])
        parent[a] = b;
    else if (height[b] < height[a])
        parent[b] = a;
    else
    {
        parent[a] = b;
        ++height[b];
    }
}

bool same(int64_t a, int64_t b)
{
    return find(a) == find(b);
}

int main()
{
    cin >> n >> m;
    parent.resize(n + 1);
    height.resize(n + 1);
    vector<edge> edges;
    for (int64_t i = 0; i < m; i++)
    {
        edge e;
        cin >> e.from >> e.to >> e.cost;
        parent[i] = i;
        height[i] = 1;
        edges.push_back(e);
    }
    for (auto &e : edges)
    {
        for (int64_t i = e.from + 1; i < m; i++)
        {
            if (e.to != i)
            {
                edge e = {e.from, i, 0};
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end(), isSmaller());
    int64_t sum = 0;
    for (auto &e : edges)
    {
        if (!same(e.from, e.to))
        {
            unite(e.from, e.to);
            sum += e.cost;
        }
    }
    cout << sum << endl;

    return 0;
}
