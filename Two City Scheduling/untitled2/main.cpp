#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int twoCitySchedCost(vector<vector<int>> &costs)
{
    struct
    {
        bool operator()(vector<int> lhs, vector<int> rhs)
        {
            bool flag = abs(lhs[0] - lhs[1]) > abs(rhs[0] - rhs[1]);
            return flag;
        }
    } cmp;

    sort(costs.begin(), costs.end(), cmp);

    int total = 0;
    int leftTotal = 0;
    int rightTotal = 0;

    for (int i = 0; i < costs.size(); ++i)
    {

        if (leftTotal == costs.size() / 2)
        {
            total += costs[i][1];
            continue;
        }

        if (rightTotal == costs.size() / 2)
        {
            total += costs[i][0];
            continue;
        }

        if (costs[i][0] < costs[i][1])
        {
            total += costs[i][0];
            leftTotal++;
        }
        else
        {
            total += costs[i][1];
            rightTotal++;
        }
    }

    return total;
}

int main()
{
    vector<vector<int>> costs1({{10, 20}, {30, 200}, {400, 50}, {30, 20}});

    vector<vector<int>> costs2(
        {{515, 563}, {451, 713}, {537, 709}, {343, 819}, {855, 779}, {457, 60}, {650, 359}, {631, 42}});

    vector<vector<int>> costs3({{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}});

    cout << twoCitySchedCost(costs1) << endl;
    cout << twoCitySchedCost(costs2) << endl;
    cout << twoCitySchedCost(costs3) << endl;
    return 0;
}
