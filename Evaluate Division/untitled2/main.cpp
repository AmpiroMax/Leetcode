#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  private:
    unordered_map<string, vector<pair<string, double>>> graph;

    double path(string start, string finish)
    {

        if (!graph.count(start) || !graph.count(finish))
            return -1.0;

        unordered_map<string, int> visited;
        queue<pair<string, double>> q;
        q.push({start, 1.0});

        while (!q.empty())
        {
            string U = q.front().first;
            double dist = q.front().second;
            q.pop();
            visited[U] = 1;

            if (U == finish)
                return dist;

            for (auto V : graph[U])
            {
                if (!visited.count(V.first))
                {
                    q.push({V.first, dist * V.second});
                }
            }
        }

        return -1.0;
    }

  public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries)
    {
        int i = 0;
        vector<double> rezult;
        for (auto edge : equations)
        {
            graph[edge[0]].push_back({edge[1], values[i]});
            graph[edge[1]].push_back({edge[0], 1.0 / values[i]});
            ++i;
        }

        for (int i = 0; i < queries.size(); ++i)
        {
            rezult.push_back(path(queries[i][0], queries[i][1]));
        }

        return rezult;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
