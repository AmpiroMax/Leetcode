#include <vector>
#include <iostream>
#include <stack>

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
    const int DIR_NUM = 2;
    enum DirType
    {
        Zig,
        Zag
    };

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> answer;
        vector<int> layer_answer;

        // zig: from left to right
        // zag: from right to left
        vector<stack<TreeNode *>> dir_stack(DIR_NUM);
        DirType curr_dir = DirType::Zig;

        dir_stack[curr_dir].push(root);
        int is_dir_changed = 0;

        while (!dir_stack[Zig].empty() || !dir_stack[Zag].empty())
        {
            if (dir_stack[Zig].empty() && is_dir_changed)
            {
                curr_dir = Zag;
                answer.push_back(layer_answer);
                layer_answer = vector<int>();
                is_dir_changed = 0;
            }

            if (dir_stack[Zag].empty() && is_dir_changed)
            {
                curr_dir = Zig;
                answer.push_back(layer_answer);
                layer_answer = vector<int>();
                is_dir_changed = 0;
            }

            TreeNode *curr_node = dir_stack[curr_dir].top();
            dir_stack[curr_dir].pop();
            if (!curr_node)
                continue;

            layer_answer.push_back(curr_node->val);

            if (curr_dir == Zig)
            {
                dir_stack[Zag].push(curr_node->left);
                dir_stack[Zag].push(curr_node->right);
            }

            if (curr_dir == Zag)
            {
                dir_stack[Zig].push(curr_node->right);
                dir_stack[Zig].push(curr_node->left);
            }
            is_dir_changed = 1;
        }

        return answer;
    }
};