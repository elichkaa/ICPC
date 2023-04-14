/*
   ID: elichka1
   TASK: friday
   LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isLeap(int n) {
    if (n % 100 == 0)
    {
        return n % 400 == 0;
    }
    return n % 4 == 0;
}

int calculateNewStart(int oldStart, int increase, int max) {
    if (oldStart <= max) {
        return oldStart + increase;
    }
    else {
        return oldStart + increase - 7;
    }
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int n;
    fin >> n;
    vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<int> fridays(7);

    int start = 1;
    for (int i = 1900; i < 1900 + n; i++)
    {
        if (isLeap(i))
        {
            daysInMonth[1] = 29;
        }
        for (int j = 0; j < 12; j++)
        {
            int thirteenth = calculateNewStart(start, 5, 2);
            fridays[thirteenth - 1] += 1;
            if (daysInMonth[j] >= 29)
            {
                int difference = 31 - daysInMonth[j];
                start = calculateNewStart(start, 3 - difference, 4);
            }
        }
        daysInMonth[1] = 28;
    }
    fout << fridays[5] << " " << fridays[6] << " " << fridays[0] << " " << fridays[1]
        << " " << fridays[2] << " " << fridays[3] << " " << fridays[4] << endl;
    return 0;
}