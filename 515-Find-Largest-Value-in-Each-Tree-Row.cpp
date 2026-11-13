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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;
        
        q.push(root);
        if(!root)
            return ans;
        

        while(!q.empty()){
            int N = q.size();
            int maxi = INT_MIN;
            while(N--){
                TreeNode* node = q.front();

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }

                maxi = max(maxi, node->val);

                q.pop();
            }

            ans.push_back(maxi);
            
        }

        return ans;
    }
};