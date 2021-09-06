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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }

    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if(node == nullptr) return;
        path.push_back(node->val);
        if(node->val == targetSum && node->left == nullptr && node->right == nullptr) {
            ans.push_back(path);
        }
        dfs(node->left, targetSum - node->val, path, ans);
        dfs(node->right, targetSum - node->val, path, ans);
        path.pop_back();
    }
};