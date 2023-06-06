#include <iostream>

using namespace std;

const int constNumbers[10] = {6, 4, 25, 8, 9, 14, 10, 19, 8, 2};

int numbers[10] = {6, 4, 25, 8, 9, 14, 10, 19, 8, 2};

void resetNumbers()
{
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = constNumbers[i];
    }
}

void hydrogen()
{
    int jm, m;
    for (int i = 0; i < 10; i++)
    {
        jm = i;
        m = numbers[jm];
        for (int j = i + 1; j < 10; j++)
        {
            if (numbers[j] > m)
            {
                jm = j;
                m = numbers[jm];
            }
        }
        for (int j = jm - 1; j >= 0; j--)
        {
            numbers[j + 1] = numbers[j];
        }
        numbers[0] = m;
    }
}

int helium(int k)
{
    int c = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (numbers[i] * numbers[j] == k)
            {
                c++;
            }
        }
    }
    return c;
}

int lithium()
{
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] != 0)
        {
            int a = numbers[i];
            numbers[i] = 0;
            int b = lithium();
            if (a < b && i < 9)
            {
                cout << b << " ";
                return b;
            }
            cout << a << " ";
            return a;
        }
    }
    return 0;
}

int main()
{
    hydrogen();
    for (int number : numbers)
    {
        cout << number << ' ';
    }
    resetNumbers();
    cout << endl
         << helium(42) << endl;
    for (int number : numbers)
    {
        cout << number << ' ';
    }
    resetNumbers();
    cout << endl
         << lithium() << endl;
    for (int number : numbers)
    {
        cout << number << ' ';
    }
    return 0;
}