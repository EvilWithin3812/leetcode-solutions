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

//DID IT MYSELF USING BFS

// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         if(!root)
//             return -1;


//         queue<TreeNode*> q;
//         q.push(root);
        
//         int result = 0;
//         int maxSum = INT_MIN;
//         int level = 1;
        

//         while(!q.empty()){
            
//             int sizee = q.size();
//             int sum = 0;
//             for(int i = 0; i < sizee; i++){
//                 TreeNode* currNode = q.front();
//                 sum += q.front()->val;
//                 if(currNode->left)
//                     q.push(currNode->left);
//                 if(currNode->right)
//                     q.push(currNode->right); 
                
//                 q.pop();
//             }

//             if(sum > maxSum){
//                 result = level;
//                 maxSum = sum;
//             }
//             level++; 

//         }

//         return result;
//     }
// };


//USING DFS SOLVING THIS

class Solution {
public:
    void dfs(TreeNode* root, int level, map<int, int>& um){
        if(!root)
            return;
        
        um[level] = um[level] + root->val;
        dfs(root->left, level+1, um);
        dfs(root->right, level+1, um);

    }

    int maxLevelSum(TreeNode* root) {
        if(!root)
            return -1;

        map<int, int> um;
        dfs(root, 1, um);
        int maxSum = INT_MIN;
        int result = 1;

        for(auto& it : um){
            if(it.second > maxSum){
                result = it.first;
                maxSum = it.second;
            }
        }

        return result;




        
    }
};