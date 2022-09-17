#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();

    while (l < r && nums[(r + l) / 2] != target)
    {
        cout << nums[(r + l) / 2] << endl;
        cout << l << " " << r << endl;
        if (target > nums[(r + l) / 2])
            l = (r + l + 1) / 2;
        else
            r = (r + l) / 2;
    }

    if (l == r)
        return 0;

    return 1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1])
            return search(matrix[i], target);
    }

    return 0;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
