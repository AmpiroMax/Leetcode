#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int is_speed_valid(vector<int> &piles, int h, int speed)
    {
        int hours_count = 0;

        for (auto bananas_count : piles)
        {
            hours_count += bananas_count / speed + (bananas_count % speed == 0 ? 0 : 1);
            if (hours_count > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max_speed = *max_element(piles.begin(), piles.end());
        int min_speed = *min_element(piles.begin(), piles.end());

        while (max_speed > min_speed)
        {
            int mid_speed = (max_speed + min_speed + 1) / 2;

            if (is_speed_valid(piles, h, mid_speed))
                max_speed = mid_speed;
            else
                min_speed = mid_speed + 1;
        }

        return max_speed;
    }
};