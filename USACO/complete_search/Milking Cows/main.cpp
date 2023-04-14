/*
   ID: elichka1
   TASK: milk2
   LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int n;
	fin >> n;
	int s = 0, e = 0;
	int milkingTime = 0, idle = 0, farmerCount = 0, ansm = 0, ansi = 0;
	vector<pair<int, int>> c;

	for (int i = 0; i < n; i++)
	{
		fin >> s >> e;
		c.push_back({s, 0});
		c.push_back({e, 1});
	}
	sort(c.begin(), c.end());

	for (int i = 0; i < c.size(); i++)
	{
		if (i != 0) {
			if (farmerCount)
			{
				milkingTime += c[i].first - c[i - 1].first;
				idle = 0;
				ansm = max(milkingTime, ansm);
			}
			else {
				idle += c[i].first - c[i - 1].first;
				milkingTime = 0;
				ansi = max(idle, ansi);
			}
		}
		if (c[i].second == 0)
		{
			farmerCount++;
		}
		else {
			farmerCount--;
		}
	}
	fout << ansm << " " << ansi << endl;
	return 0;
}