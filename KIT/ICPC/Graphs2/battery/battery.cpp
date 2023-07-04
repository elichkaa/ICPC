#include <bits/stdc++.h>

using namespace std;

int n;
int64_t m;
vector<int64_t> parent, height, counts;

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
    counts[a] = counts[a] + counts[b];
    counts[b] = counts[a];
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
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        parent.resize(n);
        height.resize(n);
        counts.resize(n);
        vector<edge> edges;
        for (int64_t j = 0; j < m; j++)
        {
            edge e;
            cin >> e.from >> e.to >> e.cost;
            edges.push_back(e);
            parent[j] = j;
            height[j] = 1;
            counts[j] = 1;
        }
        sort(edges.begin(), edges.end(), isSmaller());

        int64_t visited = 0;
        int64_t minBat = 0;

        for (auto &e : edges)
        {
            if (!same(e.from, e.to))
            {
                unite(e.from, e.to);
                counts[0] = counts[find(0)];
                if (minBat < e.cost)
                    minBat = e.cost;
            }
            if (counts[0] >= 1 + (0.75 * (n - 1)))
                break;
        }
        cout << minBat << endl;
    }

    return 0;
}
