#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();

    while (l < r && nums[(r + l) / 2] != target)
    {
        cout << nums[(r + l) / 2] << endl;
        cout << l << " " << r << endl;
        if (target > nums[(r + l) / 2])
            l = (r + l + 1) / 2;
        else
            r = (r + l) / 2;
    }

    if (l == r)
        return -1;

    return (l + r) / 2;
}

int main()
{
    vector<int> nums({-1, 0, 3, 5, 9, 12});
    int target = 0;

    cout << search(nums, target) << endl;

    return 0;
}
