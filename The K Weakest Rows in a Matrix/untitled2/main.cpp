#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    struct
    {
        bool operator()(pair<int, int> lhs, pair<int, int> rhs)
        {
            if (lhs.first == rhs.first)
                return lhs.second > rhs.second;
            return lhs.first > rhs.first;
        }
    } cmp;

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue;

    for (int i = 0; i < mat.size(); ++i)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size() && mat[i][j] != 0; ++j)
            count++;
        queue.push({count, i});
    }

    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        ans.push_back(queue.top().second);
        queue.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat({
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1},
    });
    int k = 3;

    vector<int> ans = kWeakestRows(mat, k);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}
