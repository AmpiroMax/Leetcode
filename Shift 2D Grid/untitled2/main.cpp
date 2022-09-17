#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        int n = ans.size();
        int m = ans[0].size();

        for (int i = 0; i < ans.size(); ++i)
        {
            for (int j = 0; j < ans[0].size(); ++j)
            {
                ans[(i + (j + k) / m) % n][(j + k) % m] = grid[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
