#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{

    if (!root)
        return 0;

    queue<pair<TreeNode *, int>> q;
    int depth = 1;

    q.push({root, depth});

    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        depth = q.front().second;
        q.pop();

        if (curr->left)
            q.push({curr->left, depth + 1});

        if (curr->right)
            q.push({curr->right, depth + 1});
    }

    return depth;
}

int main()
{

    return 0;
}
