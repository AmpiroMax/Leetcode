#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;
        for (; i >= 0 && j >= 0; --i, --j)
        {
            if (s[i] == '#')
            {
                for (int backspace_count = 0; i >= 0 && (s[i] == '#' || backspace_count != 0); --i)
                {
                    if (s[i] == '#')
                        backspace_count += 1;
                    else
                        backspace_count -= 1;
                }
            }

            if (t[j] == '#')
            {
                for (int backspace_count = 0; j >= 0 && (t[j] == '#' || backspace_count != 0); --j)
                {
                    if (t[j] == '#')
                        backspace_count += 1;
                    else
                        backspace_count -= 1;
                }
            }

            if (i == -1 && j == -1)
                return true;

            if (i == -1 && j != -1 || i != -1 && j == -1)
                return false;

            if (s[i] != t[j])
                return false;
        }

        for (int backspace_count = 0; i >= 0 && (s[i] == '#' || backspace_count != 0); --i)
        {
            if (s[i] == '#')
                backspace_count += 1;
            else
                backspace_count -= 1;
        }

        for (int backspace_count = 0; j >= 0 && (t[j] == '#' || backspace_count != 0); --j)
        {
            if (t[j] == '#')
                backspace_count += 1;
            else
                backspace_count -= 1;
        }

        return i == j;
    }
};

int main()
{
    Solution my_sol;
    cout << my_sol.backspaceCompare("nzp#o#g", "b#nzp#o#g") << endl;
    return 0;
}