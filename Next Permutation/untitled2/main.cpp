#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }

    if (i > 0)
    {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i])
        {
            j--;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int k = nums.size() - 1;
    for (int j = i; j < k; ++j, k--)
    {
        int tmp = nums[k];
        nums[k] = nums[j];
        nums[j] = tmp;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
