#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int64_t arr[n], dp_up[n], dp_down[n], m = 0;
    for (int i = 0; i < n; i++)
    {
        dp_up[i] = 1;
        dp_down[i] = 1;
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int maxj = 1;
        for (int j = i; j < n; j++)
        {
            if (arr[j - 1] < arr[j] && dp_up[j - 1] <= dp_up[j])
            {
                dp_up[i] = j - i;
                maxj = j;
            }
        }
        for (int j = maxj; j < n; j++)
        {
            if (arr[j] > arr[j - 1] && dp_down[j] >= dp_down[j - 1])
            {
                dp_down[i] = j - i;
            }
        }
        m = max(m, dp_up[i] + dp_down[i]);
    }
    cout << m << endl;
    return 0;
}