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

 // level order code for this

// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         bool past = false;
//         while(!q.empty()){
//             TreeNode* curr = q.front();
//             q.pop();

//             if(curr == NULL){
//                 past = true;
//             }
//             else{
//                 if(past == true){
//                     return false;
//                 }
//                 q.push(curr->left);
//                 q.push(curr->right);
//             }
//         }
//     return true;

//     }
// };

// now we will do with bfs

class Solution {
public:
    int count(TreeNode* root){
        if(!root)
            return 0;
        
        return 1 + count(root->left) + count(root->right);
    }

    bool bfs(TreeNode* root, int i, int count){
        if(root == NULL)
            return true;

        if(i >= count)
            return false;
        
        return bfs(root->left, 2*i+1, count) &&
                bfs(root->right, 2*i+2, count);

    }

    bool isCompleteTree(TreeNode* root) {
        int countNode = count(root);
        return bfs(root, 0, countNode);

    }
};