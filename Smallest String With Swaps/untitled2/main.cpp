#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  private:
    unordered_map<int, vector<int>> graph;
    vector<pair<vector<char>, vector<int>>> sets;

    vector<int> componets;
    int typesCount;
    string str;

  public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        str = s;
        sets.resize(s.size());
        componets = vector<int>(s.size(), -1);

        for (int i = 0; i < pairs.size(); ++i)
        {
            int a = pairs[i][0];
            int b = pairs[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        findComponents();

        for (auto comp : componets)
            cout << comp << " ";
        cout << endl;

        sortString(s);

        return s;
    }

  private:
    void dfs(int v, int componentType)
    {
        componets[v] = componentType;

        sets[componentType].first.push_back(str[v]);
        sets[componentType].second.push_back(v);

        for (auto u : graph[v])
        {
            if (componets[u] == -1)
            {
                dfs(u, componentType);
            }
        }
    }

    void findComponents()
    {
        typesCount = 0;
        for (int i = 0; i < componets.size(); ++i)
        {
            if (componets[i] == -1)
            {
                dfs(i, typesCount);
                typesCount++;
            }
        }
    }

    void sortString(string &rezult)
    {
        for (int type = 0; type < typesCount; ++type)
        {
            sort(sets[type].first.begin(), sets[type].first.end());
            sort(sets[type].second.begin(), sets[type].second.end());

            for (int i = 0; i < sets[type].second.size(); ++i)
            {
                rezult[sets[type].second[i]] = sets[type].first[i];
            }
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
