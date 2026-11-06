class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y)
            return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int component = n;
        for(auto xd : edges){
            int x = find(xd[0], parent);
            int y = find(xd[1], parent);
            Union(x, y, parent, rank);
            
        }

        unordered_map<int, int> um;

        for(int i = 0; i < n; i++){
            int xd = find(i, parent);
            um[xd]++;
        }

        long long result = 0;
        long long remaining = n;
        for(auto& it : um){
            long long size = it.second;
            result += size * (remaining - size);
            remaining = remaining - size;
        }

        return result;

    }
};