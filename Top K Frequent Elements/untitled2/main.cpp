#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> rezult;
        priority_queue<pair<int, int>> queue;
        unordered_map<int, pair<int, int>> hash;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!hash.count(nums[i]))
            {
                hash[nums[i]] = {0, 0};
            }
            hash[nums[i]].first++;
        }

        for (auto el : nums)
        {
            if (!hash[el].second)
            {
                queue.push({hash[el].first, el});
                hash[el].second = 1;
            }
        }

        for (int i = 0; i < k; ++i)
        {
            rezult.push_back(queue.top().second);
            queue.pop();
        }
        return rezult;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
