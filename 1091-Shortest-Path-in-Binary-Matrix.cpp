// class Solution {
// public:

//     bool isSafe(vector<vector<int>>& grid, int x, int y){
//         if(0 <= x && x < grid.size() 
//         && 0 <= y && y < grid.size()){
//             return true;
//         }

//         return false;

//     }

//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int N = grid.size();
//         if(grid[0][0] == 1)
//             return -1;

//         queue<pair<int, int>> q;
//         q.push({0,0});
//         grid[0][0] = 1;

//         vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}};

//         int level = 0;
//         while(!q.empty()){
//             int sizee = q.size();
//             while(sizee--){
//                 auto curr = q.front();
//                 q.pop();

//                 int x = curr.first;
//                 int y = curr.second;

//                 if(x == N-1 && y == N-1)
//                     return level + 1;
                
//                 for(const auto& dir : directions){
//                     int x_ = x + dir[0];
//                     int y_ = y + dir[1];
//                     if(isSafe(grid, x_, y_) && grid[x_][y_] == 0){
//                         q.push({x_, y_});
//                         grid[x_][y_] = 1;
//                     }
//                 }  

//             }
//             level++; 
//         }

//         return -1;

//     }
// };




class Solution {
public:

    bool isSafe(vector<vector<int>>& grid, int x, int y){
        if(0 <= x && x < grid.size() 
        && 0 <= y && y < grid.size()){
            return true;
        }

        return false;

    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if(grid[0][0] == 1)
            return -1;

        priority_queue<
                    pair<int, pair<int, int>>,
                     vector<pair<int, pair<int, int>>>,
                      greater<pair<int,pair<int, int>>>> pq;


        pq.push({0,{0,0}});
       
        

        vector<vector<int>> v(N, vector<int>(N, INT_MAX));
        v[0][0]= 0;


        vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(d > v[x][y]) continue;

            for(const auto& dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(grid, x_, y_) && grid[x_][y_] == 0){
                    int wt = 1 + d;
                    if(wt < v[x_][y_]){
                        v[x_][y_] = wt;
                        pq.push({wt, {x_, y_}});
                    }
                }
            }

        }
        if(v[N-1][N-1] == INT_MAX)
            return -1;

        return v[N-1][N-1] + 1;

    }
};