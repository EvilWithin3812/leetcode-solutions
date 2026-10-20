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



// extra O(N) space we are taking for vector so this
// is bad approach we can do it better than this without any extra space


// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& ans){
//         if(root == NULL)
//             return;

//         inorder(root->left, ans);
//         ans.push_back(root->val);
//         inorder(root->right, ans);

//     }

//     int getMinimumDifference(TreeNode* root) {
//         vector<int> ans;
//         inorder(root, ans);
//         int N = ans.size();

//         int mini = INT_MAX;
        
//         for(int i = 1; i < N; i++){
//             mini = min(mini, ans[i] - ans[i-1]);
//         }

//         return mini;
    
//     }
// };



//better approach space complexity is O(1) in this 


class Solution {
public:

    void inorder(TreeNode* root, TreeNode* & prev, int& minDiff){
        if(root == NULL)
            return;
        
        inorder(root->left, prev, minDiff);
        if(prev != NULL){
            minDiff = min(minDiff, root->val - prev->val);
        }
        
        prev = root;
        inorder(root->right, prev, minDiff);
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};