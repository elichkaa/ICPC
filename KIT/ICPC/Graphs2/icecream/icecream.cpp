#include <bits/stdc++.h>

using namespace std;

int n;
int64_t m;
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
    costs.resize(n + 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> costs[i];
        edge e = {i, n, costs[i]};
        edges.push_back(e);
        parent[i] = i;
        height[i] = 1;
    }
    parent[n] = n;
    height[n] = 1;
    for (int64_t i = 0; i < m; ++i)
    {
        edge e;
        cin >> e.from >> e.to >> e.cost;
        edges.push_back(e);
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
