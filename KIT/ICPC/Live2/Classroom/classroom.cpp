#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool canRearrange(vector<vector<int>> &grid)
{
    int i = 0, j = n - 1, m = 1;
    grid[i][j] = m;
    while (m < n * n)
    {
        i--;
        j--;
        m++;
        if (i < 0 && j >= 0)
        {
            i = n - 1;
        }
        else if (j < 0 && i >= 0)
        {
            j = n - 1;
            i += 1;
        }
        else if (i < 0 && j < 0)
        {
            i = n - 1;
            j += 1;
        }
        else if (grid[i][j] != 0)
        {
            i = i + 2;
            j = j + 1;
        }
        grid[i][j] = m;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(grid[i][j] - grid[i + 1][j]) == 1)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> n;
    if (n == 2)
    {
        cout << "impossible" << endl;
        return 0;
    }

    vector<vector<int>> grid(n, vector<int>(n, 0));
    if (canRearrange(grid))
    {
        cout << "possible" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}