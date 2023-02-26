#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size() + 1;
        int m = word2.size() + 1;
        vector<vector<int>> distance(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
            distance[i][0] = i;

        for (int j = 0; j < m; ++j)
            distance[0][j] = j;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (word1[i] == word2[j])
                {
                    distance[i][j] = distance[i - 1][j - 1];
                }
                else
                {
                    distance[i][j] = min(min(distance[i - 1][j], distance[i][j - 1]), distance[i - 1][j - 1]) + 1;
                }
            }
        }

        return distance[n - 1][m - 1];
    }
};