#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height)
{
    int sum = 0;
    int globMax = 0;

    for (int i = 0; i < height.size(); ++i)
    {
        if (height[i] > globMax)
            globMax = height[i];
    }

    int leftI = 0;
    int currMax = height[leftI];

    while (height[leftI] < globMax)
    {

        sum += currMax - height[leftI];

        leftI++;
        if (height[leftI] > currMax)
            currMax = height[leftI];
    }

    int rightI = height.size() - 1;
    currMax = height[rightI];

    while (height[rightI] < globMax)
    {
        sum += currMax - height[rightI];

        rightI--;
        if (height[rightI] > currMax)
            currMax = height[rightI];
    }

    for (int i = leftI; i < rightI; i++)
    {
        sum += globMax - height[i];
    }

    return sum;
}

int main()
{
    vector<int> vec1({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    vector<int> vec2({4, 2, 0, 3, 2, 5});
    cout << trap(vec1) << endl;
    cout << trap(vec2) << endl;
    return 0;
}
