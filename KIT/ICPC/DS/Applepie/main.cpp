#include <bits/stdc++.h>

using namespace std;

struct house
{
    int64_t ponies;
    int64_t pies;

    bool operator<(const house &other) const
    {
        return ponies * other.pies < other.ponies * pies;
    }
};

int main()
{
    int64_t h, pi, po;
    cin >> h >> pi;
    priority_queue<house> houses;
    for (int i = 0; i < h; i++)
    {
        cin >> po;
        houses.push({po, 1});
    }
    int i = pi - h;
    while (i > 0)
    {
        house h1 = houses.top();
        houses.pop();
        h1.pies++;
        houses.push(h1);
        i--;
    }
    cout << (houses.top().ponies + houses.top().pies - 1) / houses.top().pies << endl;
    return 0;
}