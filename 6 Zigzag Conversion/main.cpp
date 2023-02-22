#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int strings_lenght = s.size();
        vector<vector<char>> zig_zag_string(numRows, vector<char>(strings_lenght, '#'));

        int k = 0;
        int delta_i = 1;
        for (int j = 0; j < strings_lenght && k < s.size(); ++j)
        {
            if (delta_i == 1)
            {
                for (int i = 0; i < numRows && k < s.size(); ++i, ++k)
                    zig_zag_string[i][j] = s[k];
                delta_i = -1;
                continue;
            }

            if (delta_i == -1)
            {
                for (int i = numRows - 2; i >= 1 && k < s.size(); --i, ++j, ++k)
                    zig_zag_string[i][j] = s[k];
                delta_i = 1;
                --j;
                continue;
            }
        }

        string ans = "";
        for (auto str : zig_zag_string)
        {
            for (auto sim : str)
            {
                if (sim != '#')
                    ans += sim;
            }
        }
        return ans;
    }
};

int main()
{
    Solution my_sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << my_sol.convert(s, numRows) << endl;

    return 0;
}