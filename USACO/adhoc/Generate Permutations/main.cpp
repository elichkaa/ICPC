// given an array and its length k, generate all the permutations in the array and print them
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void generatePermutation(int array[], int k, int n)
{
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        return;
    }
    generatePermutation(array, k - 1, n);
    for (int i = 0; i < k - 1; i++)
    {
        if (k % 2 == 0)
        {
            swap(array[i], array[k - 1]);
        }
        else
        {
            swap(array[0], array[k - 1]);
        }
        generatePermutation(array, k - 1, n);
    }
}

int main()
{
    int n = 0, k = 0;
    cin >> k;
    int *arr;
    arr = new int[k];
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        arr[i] = n;
    }
    generatePermutation(arr, k, k);

    return 0;
}