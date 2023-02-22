#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;

        int count = 0;
        int curr_prod = 1;
        int I_INCR_FLAG = 0;
        for (int i = 0, j = 0; i < nums.size() && j < nums.size();)
        {
            if (!I_INCR_FLAG)
                curr_prod *= nums[j];

            if (curr_prod < k)
            {
                count += j - i + 1;
                ++j;
                I_INCR_FLAG = 0;
            }
            else
            {
                curr_prod /= nums[i];
                ++i;
                I_INCR_FLAG = 1;
            }
        }

        return count;
    }
};

int main()
{
    Solution my_sol;

    vector<int> nums({1, 2, 3});
    int k = 0;

    cout << my_sol.numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}