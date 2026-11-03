class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        
        visited[i] = true;
        for(int j = 0; j < isConnected[i].size(); j++){
            int val = j;

            if(isConnected[i][j] == 1 && !visited[val]){
                dfs(isConnected, visited, val);
            }
        }


    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        int count = 0;

        vector<bool> visited(N, false);

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    
    }
};