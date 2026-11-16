class Solution {
public:
    pair<int, int> findDist(unordered_map<int, vector<int>>& um, int src, int N){
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int level = 0;
        int node = src;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int curr = q.front();
                q.pop();
                for(const auto& xd : um[curr]){
                    if(!visited[xd]){
                        q.push(xd);
                        visited[xd] = true;
                    }
                }
                src = curr;
            }
            level++;
        }

        return {src, level-1};

    } 

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N1 = edges1.size() + 1;
        int N2 = edges2.size() + 1;
        if(edges1.size() == 0 && edges2.size() == 0)
            return 1;
        unordered_map<int, vector<int>> edge1;
        unordered_map<int, vector<int>> edge2;

        for(int i = 0; i < edges1.size(); i++){
            int u = edges1[i][0];
            int v = edges1[i][1];

            edge1[u].push_back(v);
            edge1[v].push_back(u);
        }

        for(int i = 0; i < edges2.size(); i++){
            int u = edges2[i][0];
            int v = edges2[i][1];

            edge2[u].push_back(v);
            edge2[v].push_back(u);
        }

        pair<int, int> p1 = findDist(edge1, 0, N1); // p1.first is my one end of diameter
        pair<int, int> p2 = findDist(edge1, p1.first, N1); // p2.first is my second end of diameter, p2.second is my level

        pair<int, int> p3 = findDist(edge2, 0, N2); // p3.first is my one end of diameter
        pair<int, int> p4 = findDist(edge2, p3.first, N2); // p4.first is my second end of diameter, p2.second is my level

        int d1 = p2.second;
        int d2 = p4.second;

        int d3 = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, d3});






    }
};