
#include <vector>
#include <iostream>
#include <unordered_map>

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
    struct NodeData
    {
        int inorder_idx;
        int postorder_idx;
    };

public:
    TreeNode *construct_tree(int in_beg, int in_end, int post_beg, int post_end, vector<int> &inorder, vector<int> &postorder, unordered_map<int, NodeData> &value_to_idx)
    {
        if (post_end - post_beg == 0)
            return nullptr;

        int root_val = postorder[post_end - 1];

        if (post_end - post_beg == 1)
            return new TreeNode(root_val);

        if (post_end - post_beg == 2)
        {
            TreeNode *root = new TreeNode(root_val);
            TreeNode *child = new TreeNode(postorder[post_beg]);

            if (postorder[post_beg] != inorder[in_beg])
                root->right = child;
            else
                root->left = child;

            return root;
        }

        int right_subtree_size = in_end - (value_to_idx[root_val].inorder_idx + 1);

        int right_in_beg = value_to_idx[root_val].inorder_idx + 1;
        int right_in_end = in_end;

        int right_post_beg = value_to_idx[root_val].postorder_idx - right_subtree_size;
        int right_post_end = value_to_idx[root_val].postorder_idx;

        TreeNode *right = construct_tree(right_in_beg, right_in_end, right_post_beg, right_post_end, inorder, postorder, value_to_idx);

        int left_subtree_size = value_to_idx[root_val].inorder_idx - in_beg;

        int left_in_beg = in_beg;
        int left_in_end = in_beg + left_subtree_size;

        int left_post_beg = post_beg;
        int left_post_end = post_beg + left_subtree_size;

        TreeNode *left = construct_tree(left_in_beg, left_in_end, left_post_beg, left_post_end, inorder, postorder, value_to_idx);

        TreeNode *root = new TreeNode(root_val);
        root->left = left;
        root->right = right;

        return root;
    }
    /*
    in:   B1 b B2 a C1 c C2
    post: B2 B2 b C1 C2 c a

    The most dificult part is to determin weather curr root has right child
    and is right child has left child 
    */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, NodeData> value_to_idx;

        for (int i = 0; i < inorder.size(); ++i)
            value_to_idx[inorder[i]].inorder_idx = i;

        for (int i = 0; i < postorder.size(); ++i)
            value_to_idx[postorder[i]].postorder_idx = i;

        int n = inorder.size();
        TreeNode *root = construct_tree(0, n, 0, n, inorder, postorder, value_to_idx);

        return root;
    }
};