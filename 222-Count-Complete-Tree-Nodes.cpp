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
    
    int getLH(TreeNode* root){
        TreeNode* temp = root;
        int lh = 0;
        while(temp != NULL){
            temp = temp->left;
            lh++;
        }
        return lh;
    }

    int getRH(TreeNode* root){
        TreeNode* temp = root;
        int rh = 0;
        while(temp != NULL){
            temp = temp->right;
            rh++;
        }
        return rh;
    }


    int solve(TreeNode* root){
        if(!root)
            return 0;
        
        int lh = getLH(root);
        int rh = getRH(root);

        if(lh == rh)
            return(pow(2, lh) - 1);
        
        return solve(root->left) + solve(root->right) + 1;
    }

    int countNodes(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};