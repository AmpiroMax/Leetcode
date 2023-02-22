#include <iostream>
#include <vector>

using namespace std;

const int MAX_LENGHT = 1e6;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> prefix_sum(1, 0);

        for (auto el : nums)
            prefix_sum.push_back(prefix_sum.back() + el);

        if (prefix_sum.back() < target)
            return 0;

        int min_lenght = MAX_LENGHT;
        for (int i = 0, j = 0; j < prefix_sum.size();)
        {
            if (prefix_sum[j] - prefix_sum[i] >= target)
            {
                min_lenght = min(j - i, min_lenght);
                ++i;
            }
            else
            {
                ++j;
            }
        }

        return min_lenght;
    }
};

int main()
{
    Solution my_sol;

    // int target = 7;
    // vector<int> nums({2, 3, 1, 2, 4, 3});

    int target = 4;
    vector<int> nums({1, 4, 4});

    cout << my_sol.minSubArrayLen(target, nums) << endl;

    return 0;
}