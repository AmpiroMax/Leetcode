#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    const int INF = 101;

    enum EdgeType
    {
        RED,
        BLUE
    };

    struct EdgesData
    {
        int vert;
        Solution::EdgeType type;
        int is_used = 0;
    };

    struct StepsData
    {
        int vert;
        Solution::EdgeType type;
        int curr_step = 0;
    };

public:
    vector<int>
    shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> distance(n, INF);
        distance[0] = 0;

        vector<vector<EdgesData>> edges(n);

        for (auto const &edge : redEdges)
            edges[edge[0]].push_back({edge[1], EdgeType::RED});

        for (auto const &edge : blueEdges)
            edges[edge[0]].push_back({edge[1], EdgeType::BLUE});

        queue<StepsData> vertices;

        vertices.push({0, EdgeType::BLUE});
        vertices.push({0, EdgeType::RED});

        while (!vertices.empty())
        {
            auto [u, prev_edge_type, curr_step] = vertices.front();
            vertices.pop();

            for (int i = 0; i < edges[u].size(); ++i)
            {
                int v = edges[u][i].vert;
                Solution::EdgeType next_edge_type = edges[u][i].type;
                int is_used = edges[u][i].is_used;

                if (prev_edge_type != next_edge_type && !is_used)
                {
                    edges[u][i].is_used = true;
                    distance[v] = min(distance[v], curr_step + 1);
                    vertices.push({v, next_edge_type, curr_step + 1});
                }
            }
        }

        for (auto &dist : distance)
            dist = dist == INF ? -1 : dist;

        return distance;
    }
};

int main()
{

    return 0;
}