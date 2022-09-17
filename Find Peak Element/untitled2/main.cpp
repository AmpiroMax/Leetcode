#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        size_t l = 0;
        size_t r = nums.size();

        bool state = false;

        while (!state)
        {
            size_t mid = (l + r) / 2;

            if (nums[mid] < nums[l])
                r = mid;
            if (nums[mid] < nums[r - 1])
                l = mid;

            // condition of number at index MID be the peak one
            state = (mid == 0 && nums[mid] > nums[mid + 1]) ||
                    (mid == (nums.size() - 1) && nums[mid] > nums[mid - 1]) ||
                    (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]);
        }

        return 0;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
