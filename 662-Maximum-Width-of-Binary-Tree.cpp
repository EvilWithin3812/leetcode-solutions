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
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        ll maxWidth = 0;
        while(!q.empty()){
            ll leftVal = q.front().second;
            ll rightVal = q.back().second;
            

            maxWidth = max(maxWidth, (rightVal - leftVal+1));
            ll N = q.size();
        
            while(N--){
                TreeNode* currNode = q.front().first;
                ll idx = q.front().second;
                q.pop();

                if(currNode->left)
                    q.push({currNode->left, 2*idx+1});
                if(currNode->right)
                    q.push({currNode->right, 2*idx+2});
            }
        }

        return maxWidth;
    }
};