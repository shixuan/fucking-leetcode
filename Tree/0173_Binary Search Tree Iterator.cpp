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
class BSTIterator {
public:
    vector<int> vals;
    int idx = 0;

    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    void traverse(TreeNode* node) {
        if(node == nullptr) return;

        traverse(node->left);
        vals.push_back(node->val);
        traverse(node->right);
    }
    
    int next() {
        return vals[idx++];
    }
    
    bool hasNext() {
        return idx != vals.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */