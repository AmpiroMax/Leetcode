#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int discharge = 0;

        for (; i >= 0 && j >= 0; --i, --j)
        {
            int sim = (a[i] - '0') + (b[j] - '0') + discharge;
            // cout << result << " " << sim << " " << discharge << endl;

            discharge = sim / 2;
            sim = sim % 2;
            result = char('0' + sim) + result;
        }

        for (; i >= 0; --i)
        {
            int sim = (a[i] - '0') + discharge;
            // cout << result << " " << sim << " " << discharge << endl;
            discharge = sim / 2;
            sim = sim % 2;
            result = char('0' + sim) + result;
        }

        for (; j >= 0; --j)
        {
            int sim = (b[j] - '0') + discharge;
            // cout << result << " " << sim << " " << discharge << endl;
            discharge = sim / 2;
            sim = sim % 2;
            result = char('0' + sim) + result;
        }
        if (discharge)
            result = "1" + result;

        return result;
    }
};

int main()
{
    string s = "ccc";
    s = "abs" + s;
    cout << s << endl;
    return 0;
}