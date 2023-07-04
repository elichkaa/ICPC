#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        cout << 2*i + 1 << " ";
    }
    cout << endl;
    return 0;
}