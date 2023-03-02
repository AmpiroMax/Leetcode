#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    const char PAD = ' ';

public:
    int compress(vector<char> &chars)
    {
        for (int i = 0; i < chars.size(); ++i)
        {
            int curr_len = 0;
            int j = i;
            for (; j < chars.size() && chars[i] == chars[j]; ++j)
                curr_len += 1;

            if (curr_len == 1)
                continue;

            vector<int> digitization;
            while (curr_len / 10 > 0)
            {
                digitization.push_back(curr_len % 10);
                curr_len /= 10;
            }
            digitization.push_back(curr_len);

            for (int k = 0; k < digitization.size(); ++k)
                chars[i + k + 1] = char('0' + digitization[digitization.size() - k - 1]);

            for (int k = i + 1 + digitization.size(); k < j; ++k)
                chars[k] = PAD;

            i = j - 1;
        }

        int last_sym_pos = 0;
        for (int i = 0; i < chars.size(); ++i)
            while (i < chars.size() && chars[i] != PAD)
                chars[last_sym_pos++] = chars[i++];

        return last_sym_pos;
    }
};