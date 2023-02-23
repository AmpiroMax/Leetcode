#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> project_data;

        for (int i = 0; i < profits.size(); ++i)
            project_data.push_back({capital[i], profits[i]});

        sort(project_data.begin(), project_data.end());

        int i = 0;
        priority_queue<int> profits_of_avaliable_projects;
        for (int j = 0; j < k; ++j)
        {
            while (i < project_data.size() && project_data[i].first <= w)
                profits_of_avaliable_projects.push(project_data[i++].second);

            if (!profits_of_avaliable_projects.empty())
            {
                w += profits_of_avaliable_projects.top();
                profits_of_avaliable_projects.pop();
            }
        }

        return w;
    }
};

int main()
{

    return 0;
}