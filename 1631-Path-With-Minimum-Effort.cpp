class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    bool isSafe(vector<vector<int>>& heights, int x, int y){
        int M = heights.size();
        int N = heights[0].size();
        if(0 <= x && x < M 
        && 0 <= y && y < N){
            return true;
        }

        return false;
    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        int M = heights.size();
        int N = heights[0].size();

        vector<vector<int>> result(M, vector<int>(N, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        result[0][0] = 0;
        pq.push({0, {0,0}});

        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == M-1 && y == N-1)
                return diff;

            for(const auto& dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(heights, x_, y_)){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if(maxDiff < result[x_][y_]){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[M-1][N-1];

    }
};