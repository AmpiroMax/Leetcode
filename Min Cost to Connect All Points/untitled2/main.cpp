#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
  private:
    vector<int> nodes;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   std::greater<pair<int, pair<int, int>>>>
        edges;

  public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int rezult = 0;
        nodes.resize(points.size());

        for (int i = 0; i < nodes.size(); ++i)
        {
            nodes[i] = i;
        }

        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {

                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push({weight, {i, j}});
            }
        }

        while (!areConnected() && !edges.empty())
        {
            int weight = edges.top().first;
            int N1 = edges.top().second.first;
            int N2 = edges.top().second.second;

            edges.pop();

            if (nodes[N1] != nodes[N2])
            {
                connectTypes(nodes[N1], nodes[N2]);
                rezult += weight;
            }
        }

        return rezult;
    }

  private:
    int areConnected()
    {
        for (int i = 0; i < nodes.size() - 1; ++i)
        {
            if (nodes[i] != nodes[i + 1])
                return false;
        }

        return true;
    }
    void connectTypes(int a, int b)
    {
        int min = 0;
        if (a <= b)
            min = a;
        else
            min = b;

        for (int i = 0; i < nodes.size(); ++i)
        {
            if (nodes[i] == a || nodes[i] == b)
            {

                nodes[i] = min;
            }
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
