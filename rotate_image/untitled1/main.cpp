#include <iostream>
#include <vector>
using namespace std;

void swap(vector<vector<int>> &m, int i, int j)
{
    int n = m.size() - 1;
    int tmp1 = m[i][j];
    int tmp2 = m[j][n - i];
    int tmp3 = m[n - i][n - j];
    int tmp4 = m[n - j][i];

    // cout << tmp1 << " " << tmp2 << endl;

    m[i][j] = tmp4;
    m[j][n - i] = tmp1;
    m[n - i][n - j] = tmp2;
    m[n - j][i] = tmp3;
}
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size() - 1;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (i >= j && i < n - j)
                swap(matrix, i, j);
        }
    }
}

int main()
{
    vector<vector<int>> vec1({{1, 2}, {3, 4}});

    vector<vector<int>> vec2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    vector<vector<int>> vec({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});

    int n = vec.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    rotate(vec);
    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
