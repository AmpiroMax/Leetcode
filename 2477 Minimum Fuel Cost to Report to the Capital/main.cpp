#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    const int INF = 1e6;

    struct Edge
    {
        int v = 0;
        int is_used = 0;
    };

    int dfs(int curr_u, int seats, vector<vector<Edge>> &graph, vector<int> &visited, vector<int> &distance, long long &total_fuel)
    {
        int child_count = 1;
        for (auto &edge : graph[curr_u])
        {
            if (!visited[edge.v])
            {
                visited[edge.v] = true;
                distance[edge.v] = distance[curr_u] + 1;
                child_count += dfs(edge.v, seats, graph, visited, distance, total_fuel);
            }
        }

        if (curr_u == 0)
            return child_count;

        total_fuel += (child_count / seats) * distance[curr_u];
        child_count = child_count % seats;

        if (child_count != 0)
            total_fuel += 1;

        return child_count;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size() + 1;

        vector<int> visited(n, 0);
        vector<int> distance(n, INF);
        distance[0] = 0;
        visited[0] = true;

        vector<vector<Edge>> graph(n);

        for (auto &edge : roads)
        {
            graph[edge[0]].push_back({edge[1], 0});
            graph[edge[1]].push_back({edge[0], 0});
        }

        long long total_fuel = 0;

        dfs(0, seats, graph, visited, distance, total_fuel);

        return total_fuel;
    }
};

int main()
{

    return 0;
}