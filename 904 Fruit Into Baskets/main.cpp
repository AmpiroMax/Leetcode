#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    const int UNIQUE_FRUIT_TYPES_NUM = 2;

public:
    int totalFruit(vector<int> &fruits)
    {
        vector<int> curr_fruit_types(2, -1);
        vector<int> curr_countinious_part_len(2, 0);

        int curr_type = 0;
        int max_len = 0;
        int curr_len = 0;
        for (int curr_tree_idx = 0; curr_tree_idx < fruits.size(); ++curr_tree_idx)
        {
            if (curr_fruit_types[curr_type] == fruits[curr_tree_idx])
            {
                curr_countinious_part_len[curr_type] += 1;
                curr_len += 1;
            }
            else
            {
                curr_type = (++curr_type) % UNIQUE_FRUIT_TYPES_NUM;
                if (curr_fruit_types[curr_type] == fruits[curr_tree_idx])
                {
                    curr_countinious_part_len[curr_type] = 1;
                    curr_len += 1;
                }
                else
                {
                    curr_countinious_part_len[curr_type] = 1;
                    curr_fruit_types[curr_type] = fruits[curr_tree_idx];

                    if (curr_len > max_len)
                        max_len = curr_len;
                    curr_len = curr_countinious_part_len[(curr_type + 1) % UNIQUE_FRUIT_TYPES_NUM];
                    curr_len += 1;
                }
            }
        }
        if (curr_len > max_len)
            max_len = curr_len;

        return max_len;
    }
};

int main()
{
    Solution my_sol;
    vector<int> fruits({1, 2, 1});

    cout << my_sol.totalFruit(fruits) << endl;
    return 0;
}