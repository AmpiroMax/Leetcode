#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) { return a[1] > b[1]; });

        int i = 0;
        int sum = 0;

        while (truckSize > 0 && (i < boxTypes.size()))
        {
            if (truckSize - boxTypes[i][0] >= 0)
            {
                truckSize -= boxTypes[i][0];
                sum += boxTypes[i][0] * boxTypes[i][1];
            }
            else
            {
                sum += (truckSize)*boxTypes[i][1];
            }
            i++;
        }
        return sum;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
