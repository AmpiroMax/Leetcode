#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
private:
    const int INF_DISTANCE = 201;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    enum TYPE
    {
        WATER,
        LAND
    };

    struct Point
    {
        int i;
        int j;
        int min_dist;
    };

    void BFS(int i, int j, const vector<vector<int>> &grid, vector<vector<int>> &distance)
    {
        int n = grid.size();
        queue<Point> steps;
        Point start;
        start.i = i;
        start.j = j;
        start.min_dist = 0;
        distance[start.i][start.j] = -1;

        steps.push(start);

        while (!steps.empty())
        {
            Point curr_point = steps.front();
            int i = curr_point.i;
            int j = curr_point.j;
            int curr_min_dist = curr_point.min_dist;
            steps.pop();

            for (auto [di, dj] : directions)
            {
                if (!(i + di >= 0 && i + di < n))
                    continue;

                if (!(j + dj >= 0 && j + dj < n))
                    continue;

                if (grid[i + di][j + dj] == TYPE::WATER && distance[i + di][j + dj] > curr_min_dist + 1)
                {
                    Point next_step;
                    next_step.i = i + di;
                    next_step.j = j + dj;
                    next_step.min_dist = curr_min_dist + 1;

                    distance[next_step.i][next_step.j] = curr_min_dist + 1;

                    steps.push(next_step);
                }

                if (grid[i + di][j + dj] == TYPE::LAND && distance[i + di][j + dj] != -1)
                {
                    Point next_step;
                    next_step.i = i + di;
                    next_step.j = j + dj;
                    next_step.min_dist = 0;

                    distance[next_step.i][next_step.j] = -1;

                    steps.push(next_step);
                }
            }
        }
    }

public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INF_DISTANCE));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    BFS(i, j, grid, distance);
            }
        }

        int max_dist = -1;
        for (auto &row : distance)
        {
            for (auto &dist : row)
            {
                if (dist > max_dist && dist != INF_DISTANCE)
                    max_dist = dist;
            }
        }

        return max_dist;
    }
};

int main()
{
    Solution my_sol;
    vector<vector<int>> grid({{0, 0, 1, 1, 1}, {0, 1, 1, 0, 0}, {0, 0, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 1}});

    cout << my_sol.maxDistance(grid) << endl;

    return 0;
}