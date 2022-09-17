#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int i = 1;
        for (; i < nums.size() && nums[i] == nums[i - 1]; ++i)
            ;

        if (i == nums.size())
            return 1;

        int dir = (nums[i] - nums[i - 1]) / abs(nums[i] - nums[i - 1]);
        int l = 2;

        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[j] != nums[j - 1])
            {
                int curr_dir = (nums[j] - nums[j - 1]) / abs(nums[j] - nums[j - 1]);

                if (curr_dir != dir)
                {
                    dir = curr_dir;
                    l++;
                }
            }
        }

        return l;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
