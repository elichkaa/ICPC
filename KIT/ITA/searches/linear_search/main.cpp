#include <bits/stdc++.h>

using namespace std;

// efficient algorithm for sorting a small number of elements
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int el;
    cout << "Enter element you are searching for: ";
    cin >> el;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            cout << "Element is at index " << i + 1 << endl;
            return 0;
        }
    }
    cout << "Element was not found." << endl;
    return 0;
}