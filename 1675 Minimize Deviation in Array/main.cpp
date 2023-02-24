#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
    const int INF = 1e9;

public:
    int minimumDeviation(vector<int> &nums)
    {
        for (auto &el : nums)
            if (el % 2 == 1)
                el *= 2;

        set<int, greater<int>> nums_set(nums.begin(), nums.end());

        int diff = INF;
        for (; *nums_set.begin() % 2 == 0;)
        {
            int max_val = *nums_set.begin();
            max_val /= 2;

            nums_set.erase(*nums_set.begin());
            nums_set.insert(max_val);

            diff = min(diff, *nums_set.begin() - *--nums_set.end());
        }

        return diff;
    }
};

int main()
{

    return 0;
}