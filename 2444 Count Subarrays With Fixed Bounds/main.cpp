#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    struct ArrData
    {
        int i;
        int j;
    };
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        vector<ArrData> subarrays;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
                continue;

            int j = i;
            for (; j < nums.size(); ++j)
                if (nums[j] < minK || nums[j] > maxK)
                    break;
            subarrays.push_back({i, j});
            i = j + 1;
        }

        for (auto [i, j] : subarrays)
            cout << i << " " << j << endl;

        return ans;
    }
};