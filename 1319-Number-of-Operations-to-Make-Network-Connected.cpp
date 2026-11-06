class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent)
            return;
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        if(connections.size() < n-1)
            return -1;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }


        for(auto xd : connections){
            int x = find(xd[0], parent);
            int y = find(xd[1], parent);
            if(parent[x] == parent[y]) continue;
            else{
                Union(xd[0], xd[1], parent, rank);
                n--;
            }
        }
        
        return n-1;

    }
};