#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> get_intersection(const vector<int> &first_interval, const vector<int> &second_interval)
    {
        int left_border = -1;
        int right_border = -1;
        left_border = max(first_interval[0], second_interval[0]);
        right_border = min(first_interval[1], second_interval[1]);

        if (left_border > right_border)
            return vector<int>({-1, -1});
        return vector<int>({left_border, right_border});
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> lists_intersections;
        for (int i = 0, j = 0; i < firstList.size() && j < secondList.size();)
        {
            cout << i << " " << j << endl;
            vector<int> curr_intersec = get_intersection(firstList[i], secondList[j]);
            if (curr_intersec[0] != -1)
                lists_intersections.push_back(curr_intersec);

            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }

        return lists_intersections;
    }
};

int main()
{
    Solution my_solve;
    // vector<vector<int>> firstList1({{0, 2}, {5, 10}, {13, 23}, {24, 25}});
    // vector<vector<int>> secondList1({{1, 5}, {8, 12}, {15, 24}, {25, 26}});

    vector<vector<int>> firstList1({{1, 3}, {5, 9}});
    vector<vector<int>> secondList1({});

    vector<vector<int>> answer = my_solve.intervalIntersection(firstList1, secondList1);

    for (auto interval : answer)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}