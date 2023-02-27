#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    void dfs_tree_creator(const vector<vector<int>> &grid, int i0, int j0, int size, Node *curr)
    {
        int is_all_equal = true;
        for (int i = i0; i < i0 + size && is_all_equal; ++i)
            for (int j = j0; j < j0 + size && is_all_equal; ++j)
                is_all_equal = grid[i0][j0] == grid[i][j];

        if (is_all_equal)
        {
            curr->isLeaf = true;
            curr->val = grid[i0][j0];
            curr->topLeft = nullptr;
            curr->topRight = nullptr;
            curr->bottomLeft = nullptr;
            curr->bottomRight = nullptr;

            return;
        }

        curr->isLeaf = false;

        curr->topLeft = new Node();
        curr->topRight = new Node();
        curr->bottomLeft = new Node();
        curr->bottomRight = new Node();

        dfs_tree_creator(grid, i0, j0, size / 2, curr->topLeft);
        dfs_tree_creator(grid, i0, j0 + size / 2, size / 2, curr->topRight);
        dfs_tree_creator(grid, i0 + size / 2, j0, size / 2, curr->bottomLeft);
        dfs_tree_creator(grid, i0 + size / 2, j0 + size / 2, size / 2, curr->bottomRight);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        Node *root = new Node();
        dfs_tree_creator(grid, 0, 0, grid.size(), root);
        return root;
    }
};