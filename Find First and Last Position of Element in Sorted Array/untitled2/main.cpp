#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            vector<int> ans = {-1, -1};
            return ans;
        }

        int beg = nums.size() / 2;
        int end = nums.size() / 2;

        vector<int> beg_lr(2);
        beg_lr[0] = 0;
        beg_lr[1] = nums.size() - 1;

        vector<int> end_lr(2);
        end_lr[0] = 0;
        end_lr[1] = nums.size() - 1;

        while (beg_lr[0] + 1 < beg_lr[1])
        {

            if (nums[beg] < target)
                beg_lr[0] = beg;
            if (nums[beg] >= target)
                beg_lr[1] = beg;

            beg = (beg_lr[1] + beg_lr[0]) / 2;
        }

        cout << beg_lr[0] << " " << beg << " " << beg_lr[1] << endl;
        beg = nums[beg_lr[0]] == target ? beg_lr[0] : beg_lr[1];

        while (end_lr[0] + 1 < end_lr[1])
        {
            if (nums[end] <= target)
                end_lr[0] = end;
            if (nums[end] > target)
                end_lr[1] = end;

            end = (end_lr[1] + end_lr[0]) / 2;
        }

        cout << end_lr[0] << " " << end << " " << end_lr[1] << endl;
        end = nums[end_lr[1]] == target ? end_lr[1] : end_lr[0];

        if (nums[beg] != target || nums[end] != target)
        {
            vector<int> ans = {-1, -1};
            return ans;
        }

        vector<int> ans = {beg, end};
        return ans;
    }
};

int main()
{
    Solution task;
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> nums2;
    vector<int> nums3 = {2, 2};
    vector<int> nums4 = {1, 2, 2};
    vector<int> nums5 = {1, 2, 2, 1};
    int target = 10;

    vector<int> rez = task.searchRange(nums1, target);

    for (auto el : rez)
    {
        cout << el << " ";
    }
    return 0;
}
