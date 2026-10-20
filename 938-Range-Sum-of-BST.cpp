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

// my solution that i already knew

// class Solution {
// public:
//     void inorder(TreeNode* root, int low, int high, int& count){
//         if(root == NULL)
//             return;

//         inorder(root->left, low, high, count);
//         if(low <= root->val && root->val <= high)
//             count+= root->val;
        
//         inorder(root->right, low, high, count);
//     }

//     int rangeSumBST(TreeNode* root, int low, int high) {
//         int count = 0;
//         inorder(root, low, high, count);
//         return count;

//     }
// };


//better approach
class Solution {
public:
    int solve(TreeNode* root, int low, int high){
        if(root == NULL)
            return 0;

        if(low <= root->val && root->val <= high){
            return root->val + solve(root->left, low, high) + solve(root->right, low, high);
        }
        
        if(root->val < low){
            return solve(root->right, low, high);
        }

        return solve(root->left, low, high);
        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);;

    }
};