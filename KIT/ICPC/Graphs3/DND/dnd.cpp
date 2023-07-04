#include <bits/stdc++.h>

using namespace std;

const int64_t INF = numeric_limits<int64_t>::max();

int main()
{
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    int m;
    cin >> m;
    vector<vector<int64_t>> dist(n, vector<int64_t>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int64_t swords = pow(p[a].first - p[b].first, 2);
        int64_t sorcery = pow(p[a].second - p[b].second, 2);
        dist[a][b] = swords + sorcery;
        dist[b][a] = swords + sorcery;
    }

    int i, k, j;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int64_t q;
    cin >> q;
    for (int s = 0; s < q; s++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        if (dist[a][b] == INF)
        {
            cout << "BRIBE DM WITH FOOD" << endl;
        }
        else
        {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}