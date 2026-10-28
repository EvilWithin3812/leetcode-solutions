//memoization + recursion

// class Solution {
// public:
//     int t[101][101];
//     int solve(int i, int j, int m, int n, vector<vector<int>>& grid){
//         if(i == m || j == n || grid[i][j] == 1)
//             return 0;
        
//         if(i == m-1 && j == n-1)
//             return 1;
        

//         if(t[i][j] != -1)
//             return t[i][j];

//         int right = solve(i, j+1, m, n, grid);
//         int down = solve(i+1, j, m, n, grid);

//         return t[i][j] = right + down;
        
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         memset(t, -1, sizeof(t));

//         return solve(0, 0, m, n, obstacleGrid);

//     }
// };


// bottom up approach 

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int row = 0; row < m; row++){
            if(row > 0 && grid[row - 1][0] == 1){
                t[row][0] = 0;
                grid[row][0] = 1;
            }
                
            else if(grid[row][0] == 1)
                t[row][0] = 0;
            else
                t[row][0] = 1;
        }

        for(int col = 0; col < n; col++){
            if(col > 0 && grid[0][col-1] == 1){
                t[0][col] = 0;
                grid[0][col] = 1;
            }
                
            else if(grid[0][col] == 1)
                t[0][col] = 0;
            else
                t[0][col] = 1;
        }


        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                if(grid[row][col] == 1){
                    t[row][col] = 0;
                }
                else{
                    t[row][col] = t[row-1][col] + t[row][col-1];
                }
            }
        }

        return t[m-1][n-1];

    }
};