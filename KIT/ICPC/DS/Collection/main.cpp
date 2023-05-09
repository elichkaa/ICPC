#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> diff;
    for (int i = 0; i < n; i++)
    {
        int64_t x;
        cin >> x;
        diff.push_back(x);
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < m; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        auto first = lower_bound(diff.begin(), diff.end(), a);
        auto second = upper_bound(diff.begin(), diff.end(), b);

        int count = distance(first, second);
        int ans = -1;
        double m = 0;

        if (count == 0)
        {
            m = 0;
        }
        else if (count % 2 == 0)
        {
            int index = count / 2 - 1;
            auto it = first;
            advance(it, index);
            m = (*it + *(next(it))) / 2.0;
        }
        else
        {
            int index = count / 2;
            auto it = first;
            advance(it, index);
            m = *it;
        }
        int uCount = 0;
        if (count > 0)
        {
            ans = *(prev(second));
            vector<int64_t> uniqueElems(first, second);
            auto last = unique(uniqueElems.begin(), uniqueElems.end());
            uCount = distance(uniqueElems.begin(), last);
        }
        cout << count << " " << uCount << " " << fixed << setprecision(1) << m << " " << ans << endl;
    }

    return 0;
}