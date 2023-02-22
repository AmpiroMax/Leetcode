#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int count1 = 0;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (i - 1 >= 0)
                {
                    if ((j - 1 >= 0) && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2))
                        count1 += 1;

                    if (board[i - 1][j] == 1 || board[i - 1][j] == 2)
                        count1 += 1;

                    if ((j + 1 < board[0].size()) && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2))
                        count1 += 1;
                }

                if ((j - 1 >= 0) && (board[i][j - 1] == 1 || board[i][j - 1] == 2))
                    count1 += 1;

                if ((j + 1 < board[0].size()) && (board[i][j + 1] == 1 || board[i][j + 1] == 2))
                    count1 += 1;

                if (i + 1 < board.size())
                {
                    if ((j - 1 >= 0) && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2))
                        count1 += 1;

                    if (board[i + 1][j] == 1 || board[i + 1][j] == 2)
                        count1 += 1;

                    if ((j + 1 < board[0].size()) && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2))
                        count1 += 1;
                }

                // 2 - lived cell that just died
                // 3 - dead cell that start living
                if (count1 < 2 || count1 > 3)
                {
                    if (board[i][j] == 1)
                        board[i][j] = 2;
                }

                if (count1 == 3 && board[i][j] == 0)
                    board[i][j] = 3;

                count1 = 0;
            }
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }

        return;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
