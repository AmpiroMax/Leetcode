#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    const int INF = 25 * 1e6;

public:
    bool is_capacity_valid(const vector<int> &weights, int days, int capacity)
    {
        int curr_ship_size = 0;
        days -= 1;
        for (int i = 0; i < weights.size(); ++i)
        {
            if (days < 0)
                return false;

            int cargo = weights[i];
            if (curr_ship_size + cargo <= capacity)
            {
                curr_ship_size += cargo;
            }
            else
            {
                curr_ship_size = 0;
                i -= 1;
                days -= 1;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int min_capacity = *max_element(weights.begin(), weights.end());
        int max_capacity = INF;

        while (max_capacity - min_capacity > 1)
        {

            int mid_capacity = (max_capacity + min_capacity) / 2;
            bool is_mid_capacity_valid = is_capacity_valid(weights, days, mid_capacity);

            if (is_mid_capacity_valid)
            {
                max_capacity = mid_capacity;
            }
            else
            {
                min_capacity = mid_capacity;
            }
        }

        if (is_capacity_valid(weights, days, min_capacity))
            return min_capacity;
        return max_capacity;
    }
};
int main()
{

    return 0;
}