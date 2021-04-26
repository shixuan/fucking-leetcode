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
    TreeNode* dummy;
    TreeNode* cur;

    TreeNode* increasingBST(TreeNode* root) {
        dummy = new TreeNode();
        cur = dummy;
        inorder(root);

        return dummy->right;
    }

    void inorder(TreeNode* root) {
        if(root == nullptr) return;

        inorder(root->left);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        inorder(root->right);
    }
};