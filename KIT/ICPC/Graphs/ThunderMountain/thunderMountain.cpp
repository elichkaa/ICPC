#include <bits/stdc++.h>

using namespace std;

struct town
{
    int x, y;
};

double distance(const town &t1, const town &t2)
{
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vector<town> towns;
        vector<vector<double>> matrix(t, vector<double>(t));

        for (int j = 0; j < t; j++)
        {
            town a;
            cin >> a.x >> a.y;
            towns.push_back(a);
        }
        for (int j = 0; j < t; j++)
        {
            for (int k = 0; k < t; k++)
            {
                double dist = distance(towns[j], towns[k]);
                if (dist <= 10)
                {
                    matrix[j][k] = matrix[k][j] = dist;
                }
                else
                {
                    matrix[j][k] = matrix[k][j] = 9999;
                }
            }
        }

        for (int k = 0; k < t; k++)
        {
            for (int p = 0; p < t; p++)
            {
                for (int j = 0; j < t; j++)
                {
                    if (matrix[p][k] + matrix[k][j] < matrix[p][j])
                        matrix[p][j] = matrix[p][k] + matrix[k][j];
                }
            }
        }
        double max = 0;
        for (int j = 0; j < t; j++)
        {
            for (int k = 0; k < t; k++)
            {
                if (matrix[j][k] > max)
                {
                    max = matrix[j][k];
                }
            }
        }

        cout << "Case #" << i + 1 << ":" << endl;
        if (max == 9999)
        {
            cout << "Send Kurdy" << endl;
        }
        else
        {
            cout << fixed << setprecision(4) << max << endl;
        }
        cout << endl;
    }

    return 0;
}