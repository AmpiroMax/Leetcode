#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size();

        while ((r - l) > 1 && nums[(l + r) / 2] != target)
        {
            int mid = (l + r) / 2;

            if (target == nums[l])
                return l;
            if (target == nums[r - 1])
                return r - 1;
            if (target > nums[r - 1] && target < nums[l])
                return -1;

            if (nums[l] < nums[r - 1])
            {
                if (nums[mid] < target)
                    l = mid;
                else
                    r = mid;
            }
            else
            {
                if (((nums[l] < target) && (target < nums[mid])) ||
                    ((target < nums[mid]) && (nums[mid] <= nums[r - 1])) ||
                    ((nums[l] < target) && (nums[mid] <= nums[r - 1]) && (target > nums[mid])))
                    r = mid;
                else if (((nums[l] <= nums[mid]) && (nums[mid] < target)) ||
                         ((nums[mid] < target) && (target < nums[r - 1])) ||
                         ((nums[l] <= nums[mid]) && (target < nums[r - 1]) && (target < nums[mid])))
                    l = mid;
            }
        }
        return nums[(l + r) / 2] == target ? (l + r) / 2 : -1;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
