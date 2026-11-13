class Solution {
public:

    int bfs(unordered_map<int, vector<int>>& adj, int N, int root){
        queue<int> q;
        int count = 0;
        vector<int> visited(N, false);
        q.push(root);
        visited[root] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(const int& xd : adj[node]){
                if(!visited[xd]){
                    visited[xd] = true;
                    q.push(xd);
                    count++;
                }
            }
        }
        return count;
    }


    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> um;
        unordered_map<int, vector<int>> adj;
        

        for(int i = 0; i < n; i++){
            int left = leftChild[i];
            int right = rightChild[i];

            if(left != -1){
                if(um.find(left) != um.end()){
                    return false;
                }
                adj[i].push_back(left);
                um[left] = i;
            
            }
            if(right != -1){
                if(um.find(right) != um.end()){
                    return false;
                }
                um[right] = i;
                adj[i].push_back(right);
            }
        }

        int root = -1;

        for(int i = 0; i < n; i++){
            if(um.find(i) == um.end()){
                if(root == -1){
                    root = i;
                }
                else{
                    return false;  //we cannot have multiple roots
                }   
            }
        }

        if(root == -1)
            return false;


        int count = bfs(adj, n, root);

        return count == n-1;



    }
};