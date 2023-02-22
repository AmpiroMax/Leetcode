#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    const int ALPHABET_SIZE = 26;

public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return vector<int>(0);

        vector<int> letters_count_p(ALPHABET_SIZE, 0);
        for (auto sim : p)
            letters_count_p[sim - 'a'] += 1;

        vector<int> anagrams_positions;

        for (int i = 0; i < (s.size() - p.size() + 1); ++i)
        {
            vector<int> curr_count = letters_count_p;
            int j = i;
            for (; j < (i + p.size()); ++j)
            {
                if (curr_count[s[j] - 'a'] == 0)
                    break;
                curr_count[s[j] - 'a'] -= 1;
            }
            if (j == (i + p.size()))
                anagrams_positions.push_back(i);
        }
        return anagrams_positions;
    }
};

int main()
{

    return 0;
}