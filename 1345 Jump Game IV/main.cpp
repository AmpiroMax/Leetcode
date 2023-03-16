#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
    const int INF = 1e9;

public:
    int minJumps(vector<int> &arr)
    {
        int start_idx = 0;
        int finish_idx = arr.size() - 1;
        unordered_map<int, vector<int>> value_to_idx;
        unordered_map<int, int> is_value_used;

        for (int i = 0; i < arr.size(); ++i)
        {
            value_to_idx[arr[i]].push_back(i);
            is_value_used[arr[i]] = 0;
        }

        vector<int> dists(arr.size(), INF);
        dists[start_idx] = 0;
        queue<int> nodes;
        nodes.push(start_idx);

        while (!nodes.empty())
        {
            int curr_node_idx = nodes.front();
            nodes.pop();

            if (curr_node_idx == finish_idx)
                break;

            if (curr_node_idx < arr.size() - 1 && dists[curr_node_idx + 1] == INF)
            {
                nodes.push(curr_node_idx + 1);
                dists[curr_node_idx + 1] = dists[curr_node_idx] + 1;
            }

            if (curr_node_idx > 0 && dists[curr_node_idx - 1] == INF)
            {
                nodes.push(curr_node_idx - 1);
                dists[curr_node_idx - 1] = dists[curr_node_idx] + 1;
            }

            if (!is_value_used[arr[curr_node_idx]])
            {
                for (int i = value_to_idx[arr[curr_node_idx]].size() - 1; i >= 0; --i)
                {
                    int next_idx = value_to_idx[arr[curr_node_idx]][i];

                    if (dists[next_idx] == INF)
                    {
                        nodes.push(next_idx);
                        dists[next_idx] = dists[curr_node_idx] + 1;
                    }
                }
            }
            is_value_used[arr[curr_node_idx]] = 1;
        }

        return dists[finish_idx];
    }
};