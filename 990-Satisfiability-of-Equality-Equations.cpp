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

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(string& str : equations){
            if(str[1] == '='){
                Union(str[0] -'a', str[3] - 'a', parent, rank);
            }
        }

        for(string& str : equations){
            if(str[1] == '!'){
                int x_parent = find(str[0] - 'a', parent);
                int y_parent = find(str[3] - 'a', parent);
                if(x_parent == y_parent)
                    return false;
            }
        }

        return true;
       

    }
};