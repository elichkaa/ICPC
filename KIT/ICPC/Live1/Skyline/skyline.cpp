#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width;
    cin >> width;
    vector<int> cols(width);
    for (int i = 0; i < width; i++)
    {
        cin >> cols[i];
    }
    sort(cols.begin(), cols.end());
    for (int i = 0; i < width; i++)
    {
        cout << cols[i] << " ";
    }
    return 0;
}