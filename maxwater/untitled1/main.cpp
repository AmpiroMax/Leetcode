#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int maxLI = 0;
    int maxRI = height.size() - 1;
    int maxArea = std::min(height[maxLI], height[maxRI]) * (maxRI - maxLI);
    int currArea = maxArea;
    int i = 0;
    int j = height.size() - 1;
    int iter = 0;
    while (i != j)
    {
        // cout << "iteration: " << iter << endl;

        if (height[maxLI] > height[maxRI])
        {
            j--;
            if (height[j] > height[maxRI])
            {
                maxRI = j;
            }
        }
        else
        {
            i++;
            if (height[i] > height[maxLI])
            {
                maxLI = i;
            }
        }

        if (j - i < 1)
            break;

        cout << "i, j, currArea, maxArea: " << i << " " << j << " " << currArea << " " << maxArea << endl;
        currArea = std::min(height[maxLI], height[maxRI]) * (maxRI - maxLI);
        if (currArea > maxArea)
            maxArea = currArea;
        iter++;
        cout << endl;
    }
    // cout << "i, j, area: " << i << " " << j << " " << maxArea << endl;
    return std::max(currArea, maxArea);
}

int main()
{
    vector<int> height0({2, 3, 4, 5, 18, 17, 6});     // 17
    vector<int> height1({1, 1});                      // 1
    vector<int> height2({4, 3, 2, 1, 4});             // 16
    vector<int> height3({1, 2, 1});                   // 2
    vector<int> height4({1, 2, 4, 3});                // 4
    vector<int> height5({1, 8, 6, 2, 5, 4, 8, 3, 7}); // 49
    cout << maxArea(height5) << endl;

    return 0;
}
