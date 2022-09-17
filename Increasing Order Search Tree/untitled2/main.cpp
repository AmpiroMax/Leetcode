#include <iostream>
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

class Solution
{
  public:
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> vals;
        in_order(root, vals);

        TreeNode *newRoot = new TreeNode();
        TreeNode *curr = newRoot;
        for (auto val : vals)
        {
            curr->val = val;
            curr->right = new TreeNode();
            curr = curr->right;
        }

        return curr->right;
    }

    void in_order(TreeNode *root, vector<int> &vals)
    {
        if (!root)
            return;

        in_order(root->left, vals);
        vals.push_back(root->val);
        in_order(root->right, vals);
    }
};

int main()
{

    return 0;
}
