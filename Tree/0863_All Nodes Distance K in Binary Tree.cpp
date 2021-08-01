/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> mp;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        return bfs(target, k);
    }

    void dfs(TreeNode* root) {
        if(root == NULL)    return;
        dfs(root->left);
        if(root->left != NULL) {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right != NULL) {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        dfs(root->right);
    }

    vector<int> bfs(TreeNode* target, int k) {
        vector<int> ans;
        vector<int> visited(500);
        queue<int> q;
        q.push(target->val);
        visited[target->val] = 1;
        
        while(!q.empty()) {
            if(k == 0) {
                while(!q.empty()) {
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
            
            int len = q.size();
            for(int i = 0; i < len; i++) {
                int front = q.front();
                q.pop();
                for(int adj : mp[front]) {
                    if(visited[adj])   continue;
                    q.push(adj);
                    visited[adj] = 1;
                }
            }

            k--;
        }
        return ans;
    }
};