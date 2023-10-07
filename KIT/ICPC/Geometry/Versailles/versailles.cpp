#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

using pt = complex<long double>;

long double cross(const pt &a, const pt &b)
{
    return imag(conj(a) * b);
}

int64_t ccw(const pt &a, const pt &b, const pt &c)
{
    return cross(b - a, c - a);
}

vector<pt> hull(vector<pt> &pts)
{
    sort(pts.begin(), pts.end(), [](const pt &a, const pt &b)
         { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    auto half_hull = [](auto begin, auto end)
    {
        vector<pt> res(end - begin);
        int64_t k = 0;
        for (auto it = begin; it != end; ++it)
        {
            while (k >= 2 && ccw(res[k - 2], res[k - 1], *it) < 0)
            {
                --k;
            }
            res[k++] = *it;
        }
        res.resize(k);
        return res;
    };
    vector<pt> lower = half_hull(pts.begin(), pts.end());
    vector<pt> upper = half_hull(pts.rbegin(), pts.rend());
    if (lower.size() == 1)
    {
        return lower;
    }
    lower.insert(lower.end(), next(upper.begin()), prev(upper.end()));
    return lower;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pt> points(n);
        for (int i = 0; i < n; ++i)
        {
            long double x, y;
            cin >> x >> y;
            points[i] = pt(x, y);
        }

        int age = 0;
        while (!points.empty())
        {
            vector<pt> convex_hull = hull(points);
            if (convex_hull.empty())
            {
                break;
            }
            age++;
            vector<pt> to_remove;
            for (const auto &p : convex_hull)
            {
                auto it = find(points.begin(), points.end(), p);
                if (it != points.end())
                {
                    to_remove.push_back(*it);
                }
            }

            for (const auto &p : to_remove)
            {
                auto it = find(points.begin(), points.end(), p);
                if (it != points.end())
                {
                    points.erase(it);
                }
            }
        }

        cout << age << endl;
    }
    return 0;
}
