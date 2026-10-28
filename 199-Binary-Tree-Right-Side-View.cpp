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

//this was using level order

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         queue<TreeNode*> q;
//         vector<int> ans;
//         if(root == NULL) return {};
//         q.push(root);

//         while(!q.empty()){
//             TreeNode* temp = NULL;
//             int n = q.size();

//             while(n--){
//                 temp = q.front();
//                 q.pop();
//                 if(temp->left != NULL)
//                     q.push(temp->left);
//                 if(temp->right != NULL)
//                     q.push(temp->right);
//             }
//             ans.push_back(temp->val);
//         }
//         return ans;
//     }
// };

//using bfs

class Solution {
public:
    void solve(TreeNode* root, int level, vector<int>& v){
        if(root == NULL)
            return;

        if(v.size() < level)
            v.push_back(root->val);

        solve(root->right, level+1, v);
        solve(root->left, level+1, v);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root, 1, v);
        return v;
    }
};