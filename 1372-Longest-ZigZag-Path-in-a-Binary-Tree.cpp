// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */


// approach 1

// class Solution {
// public:
//     void solve(TreeNode* root, int sum, bool goLeft, int& maxPath){
//         if(root == NULL)
//             return;

//         maxPath = max(maxPath, sum);

//         if(goLeft == true){
//             solve(root->left, 1+sum, false, maxPath);
//             solve(root->right, 1, true, maxPath);
//         }
//         else{
//             solve(root->right, 1+sum, true, maxPath);
//             solve(root->left, 1, false, maxPath);
//         }

//     }

//     int longestZigZag(TreeNode* root) {
//         int maxPath = 0;
//         solve(root, 0, true, maxPath);
//         solve(root, 0, false, maxPath);

//         return maxPath;

//     }
// };


//approach 2

class Solution {
public:
    void solve(TreeNode* root, int left, int right, int& maxPath){
        if(root == NULL)
            return;

        maxPath = max({maxPath, left, right});

        solve(root->left, right+1, 0, maxPath);
        solve(root->right, 0, left+1, maxPath);

    }

    int longestZigZag(TreeNode* root) {
        int maxPath = 0;
        solve(root, 0, 0, maxPath);

        return maxPath;

    }
};