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
    int MOD = 1e9+7;

    void solve(TreeNode* root, long long& maxiSum, long long totalSum, long long& currSum){
        if(root == NULL)
            return;

        long long left = 0;
        long long right = 0;

        solve(root->left, maxiSum, totalSum, left);
        solve(root->right, maxiSum, totalSum, right);
        currSum = root->val + left + right;
        long long v2 = totalSum - currSum;
        maxiSum = max(maxiSum, 1LL * currSum * v2); 
    }

    int sum(TreeNode* root){
        if(!root)
            return 0;
        
        return root->val + sum(root->left) + sum(root->right);
    }

    int maxProduct(TreeNode* root) {
        long long maxiSum = 0;
        long long totalSum = sum(root);
        cout << totalSum << endl;
        long long currSum = 0;
        solve(root, maxiSum, totalSum, currSum);
        return maxiSum % MOD;
    }
};