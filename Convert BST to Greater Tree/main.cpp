#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
  public:
    TreeNode *convertBST(TreeNode *root)
    {
        nodeSum(root, 0);
        return root;
    }

    int nodeSum(TreeNode *root, int delta)
    {
        if (!root)
            return 0;
        int sum = root->val;

        sum += nodeSum(root->right, delta);
        root->val = sum + delta;
        sum += nodeSum(root->left, delta + sum);

        return sum;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
