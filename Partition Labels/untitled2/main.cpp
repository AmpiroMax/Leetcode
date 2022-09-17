#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> partitionLabels(string s)
{
    unordered_map<int, pair<int, int>> hash;
    vector<int> sizes;
    int count = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (!hash.count(s[i]))
            hash[s[i]] = {i, i};
        else
            hash[s[i]] = {hash[s[i]].first, i};
    }

    int currLen = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (hash[s[i]].first == i)
            count++;

        if (hash[s[i]].second == i)
            count--;

        if (count == 0)
        {
            cout << i << endl;
            sizes.push_back(currLen);
            currLen = 0;
        }
        currLen++;
    }

    return sizes;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";

    for (auto el : partitionLabels(s))
    {
        cout << el << endl;
    }

    return 0;
}
