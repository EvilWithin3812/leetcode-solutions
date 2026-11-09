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

// DID IT MYSELF USING DFS
//


// class Solution {
// public:

//     void dfs(TreeNode* root, int level, int& ans){
//         if(!root)
//             return;

//         if(root->left == NULL && root->right == NULL){
//             ans = min(ans, level);
//         }

//         dfs(root->left, level + 1, ans);
//         dfs(root->right, level + 1, ans);
        
        
        
//     }

//     int minDepth(TreeNode* root) {
//         if(!root)
//             return 0;
//         int ans = INT_MAX;

//         dfs(root, 1, ans);
//         return ans;
//     }
// };


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ans = INT_MAX;

        while(!q.empty()){
            int sizee = q.size();

            while(sizee--){
                TreeNode* curr = q.front();
                if(curr->left == NULL && curr->right == NULL){
                    ans = min(ans, level);
                }
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(ans != INT_MAX){
                return ans;
            }
            level++;
        }

        return ans;
        
    }
};