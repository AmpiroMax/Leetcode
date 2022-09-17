#include <iostream>
#include <vector>

using namespace std;

int splitArray(vector<int> &nums, int m)
{
    int sum = 0;
    int maxNum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }

    int left = maxNum;
    int right = sum;
    int minMaxSum = 0;
    while (left <= right)
    {
        int currMaxSum = (left + right) / 2;
        int currSum = 0;
        int _m = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (currSum + nums[i] > currMaxSum)
            {
                _m++;
                currSum = nums[i];
            }
            else
            {
                currSum += nums[i];
            }
        }
        if (_m + 1 <= m)
        {
            minMaxSum = currMaxSum;
            right = currMaxSum - 1;
        }
        else
        {
            left = currMaxSum + 1;
        }
    }

    return minMaxSum;
}

int main()
{
    vector<int> nums1({7, 2, 5, 10, 8});
    vector<int> nums2({1, 2, 3, 4, 5});
    vector<int> nums3({3, 2, 2, 4, 1, 4});
    cout << splitArray(nums1, 2) << endl;
    return 0;
}
