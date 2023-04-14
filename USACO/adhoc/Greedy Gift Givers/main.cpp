/*
   ID: elichka1
   TASK: gift1
   LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int n, i, j;
    fin >> n;
    vector<string> people(n);
    vector<int> receivedMoney(n);
    for (i = 0; i < n; i++)
    {
        string name;
        fin >> name;
        people[i] = name;
    }
    for (j = 0; j < n; j++)
    {
        string receiver;
        fin >> receiver;
        int money, numberOfReceivers, p;
        fin >> money >> numberOfReceivers;
        if (numberOfReceivers <= 0 || money <= 0)
        {
            continue;
        }
        int toReceive = money / numberOfReceivers;
        receivedMoney[find(people.begin(), people.end(), receiver) - begin(people)] += -money + (money % numberOfReceivers);
        for (p = 0; p < numberOfReceivers; p++)
        {
            fin >> receiver;
            auto indexOfReceiver = find(people.begin(), people.end(), receiver) - begin(people);
            receivedMoney[indexOfReceiver] += toReceive;
        }
    }
    for (int i = 0; i < people.size(); i++)
    {
        fout << people[i] << " " << receivedMoney[i] << endl;
    }
    return 0;
}