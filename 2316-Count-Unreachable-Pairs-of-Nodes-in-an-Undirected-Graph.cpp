// class Solution {
// public:
//     int find(int x, vector<int>& parent){
//         if(x == parent[x])
//             return x;
        
//         return parent[x] = find(parent[x], parent);
//     }

//     void Union(int x, int y, vector<int>& parent, vector<int>& rank){
//         int parent_x = find(x, parent);
//         int parent_y = find(y, parent);

//         if(parent_x == parent_y)
//             return;

//         if(rank[parent_x] > rank[parent_y]){
//             parent[parent_y] = parent_x;
//         }
//         else if(rank[parent_x] < rank[parent_y]){
//             parent[parent_x] = parent_y;
//         }
//         else{
//             parent[parent_y] = parent_x;
//             rank[parent_x]++;
//         }
//     }

//     long long countPairs(int n, vector<vector<int>>& edges) {
//         vector<int> parent(n);
//         vector<int> rank(n, 0);
//         for(int i = 0; i < n; i++){
//             parent[i] = i;
//         }

//         int component = n;
//         for(auto xd : edges){
//             int x = find(xd[0], parent);
//             int y = find(xd[1], parent);
//             Union(x, y, parent, rank);
            
//         }

//         unordered_map<int, int> um;

//         for(int i = 0; i < n; i++){
//             int xd = find(i, parent);
//             um[xd]++;
//         }

//         long long result = 0;
//         long long remaining = n;
//         for(auto& it : um){
//             long long size = it.second;
//             result += size * (remaining - size);
//             remaining = remaining - size;
//         }

//         return result;

//     }
// };


class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& um, int i, vector<bool>& visited, long long& count){
        visited[i] = true;
        count++;
        
        for(auto xd : um[i]){
            if(!visited[xd]){
                dfs(um, xd, visited, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> um;
        for(auto& xd : edges){
            um[xd[0]].push_back(xd[1]);
            um[xd[1]].push_back(xd[0]);
        }

        
        vector<int> sizes;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                long long count = 0;
                dfs(um, i, visited, count);
                sizes.push_back(count);
            }
        }

        long long remaining = n;
        long long ans = 0;
        for(int i = 0; i < sizes.size(); i++){
            remaining -= sizes[i];
            ans += sizes[i] * remaining;
        }

        return ans;





       

    }
};