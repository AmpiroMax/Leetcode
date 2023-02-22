#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    const int INF = 1e8;

public:
    int jump(vector<int> &nums)
    {
        vector<int> min_dist(nums.size(), INF);
        min_dist[0] = 0;

        for (int i = 0; i < nums.size(); ++i)
        {

            for (int j = 1; j <= nums[i] && (i + j < nums.size()); ++j)
            {
                min_dist[i + j] = min(min_dist[i + j], min_dist[i] + 1);
                if (i + j == nums.size() - 1)
                    return min_dist[nums.size() - 1];
            }
        }

        return min_dist[nums.size() - 1];
    }
};

int main()
{

    return 0;
}