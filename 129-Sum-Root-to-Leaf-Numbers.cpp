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
// class Solution {
// public:

    

//     void traverse(TreeNode* root, string& temp, int& total){
//         if(root == NULL)
//             return;

//         temp += to_string(root->val);
//         if(root->left == NULL && root->right == NULL){
//             total += stoi(temp);
//             temp.pop_back();
//             return;
//         }
        
//         traverse(root->left, temp, total);
//         traverse(root->right, temp, total);
//         temp.pop_back();

//     }

//     int sumNumbers(TreeNode* root) {
//         string temp = "";
//         int total = 0;
//         traverse(root, temp, total);

//         return total;

//     }
// };


class Solution {
public:

    

    void traverse(TreeNode* root, int& total, int curr){
        if(root == NULL)
            return;

        curr = curr * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            total += curr;
        }
        traverse(root->left, total, curr);
        traverse(root->right, total, curr);

    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        int curr = 0;
        traverse(root, total, curr);
        return total;
    }
};