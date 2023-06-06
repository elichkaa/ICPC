#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 2;

struct TrieNode
{
    int children[ALPHABET_SIZE];
    bool end_of_word;
    bool isSubnet;

    TrieNode() : end_of_word(false)
    {
        isSubnet = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = -1;
        }
    }
};

void insertIP(vector<TrieNode> &trie, const string &ip, bool sub)
{
    int node = 0;
    for (char c : ip)
    {
        int index = c - '0';
        if (trie[node].children[index] == -1)
        {
            trie[node].children[index] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].children[index];
    }
    if (!trie[node].isSubnet)
    {
        trie[node].isSubnet = sub;
    }

    trie[node].end_of_word = true;
}

bool searchPrefix(const vector<TrieNode> &trie, const string &id)
{
    int node = 0;
    for (char c : id)
    {
        int index = c - '0';
        if (trie[node].children[index] == -1)
        {
            return false;
        }
        node = trie[node].children[index];
        if (trie[node].end_of_word && trie[node].isSubnet)
        {
            return true;
        }
    }
    return trie[node].end_of_word;
}

int main()
{
    int64_t n;
    cin >> n;
    cin.ignore();
    vector<TrieNode> trie(1);

    for (int64_t i = 0; i < n; i++)
    {
        string ip;
        getline(cin, ip);
        if (ip.find('*') != string::npos)
        {
            insertIP(trie, ip.substr(0, ip.length() - 1), true);
        }
        else
        {
            insertIP(trie, ip, false);
        }
    }

    int64_t m;
    cin >> m;
    cin.ignore();
    vector<string> ids(m);
    for (int64_t i = 0; i < m; i++)
    {
        getline(cin, ids[i]);
    }

    for (const string &id : ids)
    {
        if (searchPrefix(trie, id))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
