/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& um){
        if(!root)
            return;
        
        if(root->left != NULL){
            um[root->left] = root;
        }
        inorder(root->left, um);

        if(root->right != NULL){
            um[root->right] = root;
        }
        inorder(root->right, um);

    }

    void bfs(TreeNode* target, unordered_map<TreeNode*,TreeNode*>& um, vector<int>& ans, int k){
        unordered_set<TreeNode*> st;

        queue<TreeNode*> q;
        q.push(target);
        st.insert(target);



        while(!q.empty()){
            int N = q.size();
            
            if(k == 0)
                break;

            while(N--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != NULL && st.count(curr->left) == 0){
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right != NULL && st.count(curr->right) == 0){
                    q.push(curr->right);
                    st.insert(curr->right);
                }

                if(um.count(curr) == 1 && st.count(um[curr]) == 0){
                    q.push(um[curr]);
                    st.insert(um[curr]);
                }

            }
            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();

        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> um;
        
        vector<int> ans;
        inorder(root, um);

        bfs(target, um, ans, k);

        return ans;
        
        

    }
};