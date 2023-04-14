/*
   ID: elichka1
   TASK: beads
   LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int n;
	fin >> n;
	string beads;
	fin >> beads;
	beads = " " + beads + beads;
	int left[800][2];
	int right[800][2];
	left[0][0] = left[0][1] = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (beads[i] == 'r')
		{
			left[i][0] = left[i - 1][0] + 1;
			left[i][1] = 0;
		}
		else if (beads[i] == 'b')
		{
			left[i][1] = left[i - 1][1] + 1;
			left[i][0] = 0;
		}
		else if (beads[i] == 'w')
		{
			left[i][0] = left[i - 1][0] + 1;
			left[i][1] = left[i - 1][1] + 1;
		}
	}
	right[2 * n + 1][0] = right[2 * n + 1][1] = 0;
	for (int i = 2 * n; i >= 1; i--)
	{
		if (beads[i] == 'r')
		{
			right[i][0] = right[i + 1][0] + 1;
			right[i][1] = 0;
		}
		else if (beads[i] == 'b')
		{
			right[i][1] = right[i + 1][1] + 1;
			right[i][0] = 0;
		}
		else if (beads[i] == 'w')
		{
			right[i][0] = right[i + 1][0] + 1;
			right[i][1] = right[i + 1][1] + 1;
		}
	}
	int ans = 0;
	//splitting at each i
	for (int i = 1; i < 2 * n; i++)
	{
		ans = max(ans, max(left[i][0], left[i][1]) + max(right[i + 1][0], right[i + 1][1]));
	}
	ans = min(ans, n);
	fout << ans << endl;
	return 0;
}