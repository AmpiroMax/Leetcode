#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> array(n, vector<int>(n, 0));
        int num = 1;
        for (int cycle = 0; cycle <= (n - 1) * 2; ++cycle)
        {
            // вправо
            for (int k = cycle; k < n - cycle; ++k)
            {
                array[cycle][k] = num;
                num++;
            }

            int k = n - 1 - cycle;
            //  вниз
            for (int i = n - k; i <= k; ++i)
            {
                array[i][k] = num;
                num++;
            }

            // влево
            for (int i = k - 1; i >= n - k - 1; --i)
            {
                array[k][i] = num;
                num++;
            }

            // вверх
            for (int i = k - 1; i > n - k - 1; --i)
            {
                array[i][n - k - 1] = num;
                num++;
            }
        }

        return array;
    }
};

int main()
{
    Solution soal;
    auto ans = soal.generateMatrix(2);

    for (auto vec : ans)
    {
        for (auto el : vec)
            if (el < 10)
                cout << " " << el << " ";
            else
                cout << el << " ";
        cout << endl;
    }
    return 0;
}
