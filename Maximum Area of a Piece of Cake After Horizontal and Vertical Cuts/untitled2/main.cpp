#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_d_h = horizontalCuts[0];
        int max_d_v = verticalCuts[0];

        for (int i = 1; i < horizontalCuts.size(); ++i)
        {
            if ((horizontalCuts[i] - horizontalCuts[i - 1]) > max_d_h)
            {
                max_d_h = horizontalCuts[i] - horizontalCuts[i - 1];
            }
        }

        for (int i = 1; i < verticalCuts.size(); ++i)
        {
            if ((verticalCuts[i] - verticalCuts[i - 1]) > max_d_v)
            {
                max_d_v = verticalCuts[i] - verticalCuts[i - 1];
            }
        }

        return (1LL * max_d_h * max_d_v) % 1000000007;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
