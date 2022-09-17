#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> hash;
    hash.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!hash.count(nums[i]))
        {
            hash[nums[i]] = 1;
        }
        else
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
