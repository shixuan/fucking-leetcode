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
    int pre = -1, ans = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* node) {
        if(node == nullptr) return;
        inorder(node->left);
        if(pre == -1)
            pre = node->val;
        else {
            ans = min(ans, abs(node->val - pre));
            pre = node->val;
        }
        inorder(node->right);
    }
};