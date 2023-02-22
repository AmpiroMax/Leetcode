#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
class Solution
{
  private:
    struct data
    {
        int a = 0;
        int b = 0;
        int c = 0;
    };

public:
vector<vector<int>> threeSum(vector<int> &nums)
{
    unordered_map<int, queue<int>> hash;
    unordered_set<data, vector<int>> set;

    for (int i = 0; i < nums.size(); ++i)
    {
        hash[nums[i]].push(i);
    }

    for (int i = 0; i < nums.size(); ++i)
    {

        for (int j = i + 1; j < nums.size(); ++j)
        {
            int sum = nums[i] + nums[j];
            if (hash.count(sum))
            {
                vector<int> ans;
                ans.push_back(sum);
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                sort(ans.begin(), ans.end());
                data ans_data;
                ans_data.a = ans[0];
                ans_data.b = ans[1];
                ans_data.c = ans[2];

                set.insert(ans_data);
            }
        }
        hash[nums[i]].pop();
    }

    vector<vector<int>> answer(set);
}
};
*/

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> hash;
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            hash[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int sum = nums[i] + nums[j];
                if (hash.count(-sum))
                {
                }
            }
        }

        return answer;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
