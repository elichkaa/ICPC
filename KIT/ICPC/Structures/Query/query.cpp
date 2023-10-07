#include <bits/stdc++.h>

using namespace std;

struct node
{
    int64_t maxVal;
};

void buildSegmentTree(vector<int64_t> &cakeValues, vector<int> &isCake, vector<node> &segmentTree, int64_t node, int64_t start, int64_t end)
{
    if (start == end)
    {
        segmentTree[node].maxVal = isCake[start] == 1 ? cakeValues[start] : 0;
    }
    else
    {
        int64_t mid = (start + end) / 2;
        int64_t leftChild = 2 * node + 1;
        int64_t rightChild = 2 * node + 2;
        buildSegmentTree(cakeValues, isCake, segmentTree, leftChild, start, mid);
        buildSegmentTree(cakeValues, isCake, segmentTree, rightChild, mid + 1, end);
        segmentTree[node].maxVal = max(segmentTree[leftChild].maxVal, segmentTree[rightChild].maxVal);
    }
}

void pointUpdate(vector<node> &segmentTree, int64_t node, int64_t start, int64_t end, int64_t index, int64_t value)
{
    if (index < start || index > end)
    {
        return;
    }

    if (start == end)
    {
        if (segmentTree[node].maxVal != 0)
        {
            segmentTree[node].maxVal = value;
        }
    }
    else
    {
        int64_t mid = (start + end) / 2;
        int64_t leftChild = 2 * node + 1;
        int64_t rightChild = 2 * node + 2;

        if (index >= start && index <= mid)
        {
            pointUpdate(segmentTree, leftChild, start, mid, index, value);
        }
        else if (index >= start && index > mid)
        {
            pointUpdate(segmentTree, rightChild, mid + 1, end, index, value);
        }

        segmentTree[node].maxVal = max(segmentTree[leftChild].maxVal, segmentTree[rightChild].maxVal);
    }
}

int64_t query(vector<node> &segmentTree, int64_t node, int64_t start, int64_t end, int64_t left, int64_t right)
{
    if (start > right || end < left)
    {
        return 0;
    }

    if (start >= left && end <= right)
    {
        return segmentTree[node].maxVal;
    }

    int64_t mid = (start + end) / 2;
    int64_t leftChild = 2 * node + 1;
    int64_t rightChild = 2 * node + 2;

    int64_t leftQuery = query(segmentTree, leftChild, start, mid, left, right);
    int64_t rightQuery = query(segmentTree, rightChild, mid + 1, end, left, right);

    return max(leftQuery, rightQuery);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int64_t> cakeVals(n);
        vector<int> cakes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> cakeVals[i] >> cakes[i];
        }
        vector<node> segmentTree(4 * n);
        buildSegmentTree(cakeVals, cakes, segmentTree, 0, 0, n - 1);
        int q;
        cin >> q;
        while (q--)
        {
            int64_t type;
            cin >> type;
            if (type == 0)
            {
                int64_t pos, x;
                cin >> pos >> x;
                pointUpdate(segmentTree, 0, 0, n - 1, pos - 1, x);
            }
            else
            {
                int64_t l, r;
                cin >> l >> r;
                cout << query(segmentTree, 0, 0, n - 1, l - 1, r - 1) << endl;
            }
        }
    }
    return 0;
}