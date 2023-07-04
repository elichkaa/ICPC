#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct branch
{
    vector<int> children;
};

int main()
{
    int N;
    cin >> N;
    vector<branch> branches(pow(2, N) - 1);

    int branchin, branchout;
    for (int i = 0; i < pow(2, N) - 2; i++)
    {
        cin >> branchin >> branchout;
        branches[branchin - 1].children.push_back(branchout - 1);
    }

    int curr = 0;
    string answer;
    while (N > 1)
    {
        cout << "? " << branches[curr].children[0] + 1 << endl;
        cin >> answer;
        if (answer == "YES")
        {
            curr = branches[curr].children[0];
        }
        else
        {
            cout << "? " << branches[curr].children[1] + 1 << endl;
            cin >> answer;
            if (answer == "YES")
            {
                curr = branches[curr].children[1];
            }
            else
            {
                break;
            }
        }
        N--;
    }
    cout << "! " << curr + 1;
    return 0;
}