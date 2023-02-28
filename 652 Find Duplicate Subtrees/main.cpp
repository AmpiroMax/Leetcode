#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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
    string dfs(TreeNode *curr, unordered_map<string, vector<TreeNode *>> &subtrees)
    {
        if (!curr)
            return "";

        string str_left = dfs(curr->left, subtrees);
        string str_right = dfs(curr->right, subtrees);

        string my_name = "(" + str_left + ", " + to_string(curr->val) + ", " + str_right + ")";

        subtrees[my_name].push_back(curr);

        return my_name;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, vector<TreeNode *>> subtrees;
        dfs(root, subtrees);

        vector<TreeNode *> answer;
        for (auto [key, value] : subtrees)
        {
            if (value.size() > 1)
            {
                cout << key << endl;
                answer.push_back(value[0]);
            }
        }

        return answer;
    }
};