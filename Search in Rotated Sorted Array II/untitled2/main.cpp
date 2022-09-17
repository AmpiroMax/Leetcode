#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();

    if (nums.size() == 1)
        return target == nums[0];

    while ((r - l) > 1 && nums[l] == nums[r - 1])
    {
        if (nums[l] < nums[l + 1])
            l++;
        r--;
    }

    while ((r - l) > 1)
    {
        if (nums[(r + l) / 2] >= nums[l])
            l = (r + l) / 2;
        if (nums[(r + l) / 2] <= nums[r - 1] && nums[r - 1] < nums[l])
            r = (r + l) / 2;
    }

    int indMax = (r + l - 1) / 2;

    l = 0;
    r = indMax + 1;
    while (l < r && nums[l] <= target && target <= nums[r - 1])
    {
        if (nums[(r + l) / 2] == target)
            return 1;

        if (target > nums[(r + l) / 2])
            l = (r + l + 1) / 2;
        else
            r = (r + l) / 2;
    }

    l = indMax + 1;
    r = nums.size();
    while (l < r && nums[l] <= target && target <= nums[r - 1])
    {
        if (nums[(r + l) / 2] == target)
            return 1;

        if (target > nums[(r + l) / 2])
            l = (r + l + 1) / 2;
        else
            r = (r + l) / 2;
    }
    return 0;
}

int main()
{
    vector<int> nums1({2, 5, 6, 0, 0, 0, 2});
    int target1 = 0;

    vector<int> nums2({2, 2, 5, 6, 0, 0, 1});
    int target2 = 3;

    vector<int> nums3({1, 0, 1, 1, 1});
    int target3 = 0;

    vector<int> nums4({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1});
    int target4 = 2;

    vector<int> nums5({1});
    int target5 = 0;

    int ans = search(nums1, 0);
    cout << "Answer " << ans << endl;
    return 0;
}
