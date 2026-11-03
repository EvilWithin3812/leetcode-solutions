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
    int solve(TreeNode* root, int& maxi){
        if(root == NULL)
            return 0;
        
        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        int found_below = left + right + root->val;
        int max_from_left_and_right = max(left, right) + root->val;
        int only_root = root->val;

        maxi = max({maxi, found_below, max_from_left_and_right, only_root});
        return max(only_root, max_from_left_and_right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        int ans = solve(root, maxi);
        return maxi;
    }
};