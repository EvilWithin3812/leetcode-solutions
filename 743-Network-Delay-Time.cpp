class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> pq;

        vector<int> dist(n+1, INT_MAX);

        unordered_map<int, vector<pair<int, int>>> um;
        for(auto& xd : times){
            int u = xd[0];
            int v = xd[1];
            int w = xd[2];

            um[u].push_back({v, w});
        }

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& xd : um[node]){
                int neighbour = xd.first;
                int wt = xd.second;

                if(d+wt < dist[neighbour]){
                    dist[neighbour] = d + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            ans = max(ans, dist[i]);
        }
        
        return ans == INT_MAX ? -1 : ans;


    }
};