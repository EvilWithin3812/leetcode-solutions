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


// bad solution as we are using extra space 
// we can do it without extra space

// class Solution {
// public:
//     void inorder(TreeNode* root, unordered_map<int, int>& um){
//         if(root == NULL)
//             return;

//         inorder(root->left, um);
//         um[root->val]++;
//         inorder(root->right, um);

//     }

//     vector<int> findMode(TreeNode* root) {
//         unordered_map<int, int> um;
//         inorder(root, um);
//         vector<int> ans;
//         int maxi = INT_MIN;

//         for(auto it = um.begin(); it != um.end(); it++){
//             if(it->second == maxi){
//                 ans.push_back(it->first);
//             }
//             if(it->second > maxi){
//                 ans.clear();
//                 maxi = it->second;
//                 ans.push_back(it->first);
//             }
            

//         }

//         return ans;
//     }
// };



// better approach with O(1) space complexity

class Solution {
public:
    void inorder(TreeNode* root, int& currNum , int& currFreq, int& maxFreq, vector<int>& ans){
        if(root == NULL)
            return;
        
        inorder(root->left, currNum, currFreq, maxFreq, ans);

        if(root->val == currNum){
            currFreq++;
        } 
        else{
            currNum = root->val;
            currFreq = 1;
        }

        if(currFreq > maxFreq){
            ans.clear();
            maxFreq = currFreq;
        }

        if(currFreq == maxFreq)
            ans.push_back(root->val);

        inorder(root->right, currNum, currFreq, maxFreq, ans);

    }

    vector<int> findMode(TreeNode* root) {
        int currFreq = 0;
        int maxFreq = 0;
        int currNum = INT_MAX;
        vector<int> ans;

        inorder(root, currNum, currFreq, maxFreq, ans);

        return ans;
    }
};