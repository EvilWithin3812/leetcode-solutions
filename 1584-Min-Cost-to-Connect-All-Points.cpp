class Solution {
public:
    int mst(unordered_map<int, vector<pair<int, int>>>& um, int N){
        int sum = 0;
        vector<bool> visited(N, false);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>> 
        > pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            int wt = curr.first;

            if(visited[node] == true)
                continue;
            
            visited[node] = true;
            sum += wt;

            for(const auto& xd : um[node]){
                int neighbour = xd.first;
                int wt = xd.second;

                if(visited[neighbour] == false)
                    pq.push({wt, neighbour});
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> um;
        int N = points.size();

        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                um[i].push_back({j, dist});
                um[j].push_back({i, dist});
            }
        }

        return mst(um, N);


    }
};