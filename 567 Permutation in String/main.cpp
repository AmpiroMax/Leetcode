#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    const int ALPHABET_SIZE = 26;

public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> s1_count(ALPHABET_SIZE, 0);
        for (int i = 0; i < s1.size(); ++i)
            s1_count[s1[i] - 'a'] += 1;

        for (int i = 0; i < s2.size(); ++i)
        {
            vector<int> curr_count = s1_count;
            int j = i;

            for (; j < s2.size() && (j - i < s1.size()); ++j)
            {
                if (curr_count[s2[j] - 'a'] == 0)
                {
                    while (s2[i] != s2[j] && i < j)
                    {
                        curr_count[s2[i] - 'a'] += 1;
                        i++;
                    }

                    if (i == j)
                        break;

                    curr_count[s2[i] - 'a'] += 1;
                    i++;
                }
                curr_count[s2[j] - 'a'] -= 1;
            }

            if (j - i == s1.size())
                return true;
        }

        return false;
    }
};

int main()
{
    Solution my_sol;
    string s1 = "hello";
    string s2 = "ooolleoooleh";

    cout << my_sol.checkInclusion(s1, s2) << endl;
    return 0;
}