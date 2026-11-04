// class Solution {
// public:
//     void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        
//         visited[i] = true;
//         for(int j = 0; j < isConnected[i].size(); j++){
//             int val = j;

//             if(isConnected[i][j] == 1 && !visited[val]){
//                 dfs(isConnected, visited, val);
//             }
//         }


//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int N = isConnected.size();
//         int count = 0;

//         vector<bool> visited(N, false);

//         for(int i = 0; i < N; i++){
//             if(!visited[i]){
//                 dfs(isConnected, visited, i);
//                 count++;
//             }
//         }

//         return count;
    
//     }
// };



class Solution {
public:

    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int j = 0; j < isConnected[curr].size(); j++){
                int val = j;
                if(isConnected[curr][val] == 1 && !visited[j]){
                    q.push(val);
                    visited[val] = true;
                }
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        int count = 0;
        vector<bool> visited(N, false);

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                bfs(isConnected, visited, i);
                count++;
            }
        }
        return count;

        
    
    }
};