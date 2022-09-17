#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, vector<int>> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        hash[nums[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << i << endl;
        cout << target << " " << target - nums[i] << endl;
        if (hash.count(target - nums[i]))
        {
            if (target - nums[i] == nums[i])
            {
                cout << "Size " << hash[nums[i]].size() << endl;
                if (hash[nums[i]].size() > 1)
                    return vector<int>({hash[nums[i]][0], hash[nums[i]][1]});
            }
            else
                return vector<int>({hash[nums[i]][0], hash[target - nums[i]][0]});
        }
    }

    return vector<int>({-1, -1});
}

int main()
{
    vector<int> nums({3, 3});
    int target = 6;

    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
