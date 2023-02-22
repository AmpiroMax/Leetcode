#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool isGreater(const string &str1, const string &str2, const vector<int> &order)
    {
        for (int i = 0; i < str1.size(); i++)
        {
            if (str2.size() <= i)
                return false;
            int str1_letter_i_order = order[str1[i] - 'a'];
            int str2_letter_i_order = order[str2[i] - 'a'];

            if (str1_letter_i_order < str2_letter_i_order)
                return true;
            if (str1_letter_i_order > str2_letter_i_order)
                return false;
        }
        return true;
    }

public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> normal_2_alian_order_mapping(order.size());
        for (int i = 0; i < order.size(); ++i)
        {
            normal_2_alian_order_mapping[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i)
        {
            bool is_first_greater = isGreater(words[i], words[i + 1], normal_2_alian_order_mapping);
            if (!is_first_greater)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution my_sol;

    vector<string> words({"hello", "leetcode"});
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    cout << my_sol.isAlienSorted(words, order) << endl;

    return 0;
}