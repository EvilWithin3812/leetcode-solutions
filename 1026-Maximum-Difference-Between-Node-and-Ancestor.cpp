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

// Brute force that i did myself
// we can do better than this for sure though

// class Solution {
// public:
//     void solve(TreeNode* root, int& maxi, int vali){
//         if(root == NULL)
//             return;

//         maxi = max(maxi, abs(root->val - vali));
//         solve(root->left, maxi, vali);
//         solve(root->right, maxi, vali);
        
//     }
//     void inorder(TreeNode* root, int& maxi){
//         if(!root)
//             return;

//         solve(root, maxi, root->val);
//         inorder(root->left,maxi);
//         inorder(root->right, maxi);

//     }

//     int maxAncestorDiff(TreeNode* root) {
//         int maxi = 0;
//         inorder(root, maxi);
//         return maxi;
//     }
// };



class Solution {
public:

    void solve(TreeNode* root, int maxi, int mini, int& ans){
        if(root == NULL){
            ans = max(ans, abs(maxi - mini));
            return;
        }

        maxi = max(root->val, maxi);
        mini = min(root->val, mini);
        solve(root->left, maxi, mini, ans);
        solve(root->right, maxi, mini, ans);

    }

    int maxAncestorDiff(TreeNode* root) {
        int maxi = root->val;
        int mini = root->val;
        int ans = 0;
        solve(root, maxi, mini, ans);
        return ans;

    }
};