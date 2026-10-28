//recursion + memoization 

// class Solution {
// public:
//     int t[201][201];

//     int solve(int i, int j, int m, int n, vector<vector<int>>& grid){
//         if(i == m-1 && j == n-1)
//             return t[i][j] = grid[i][j];

//         if(t[i][j] != -1)   
//             return t[i][j];
        
//         if(i == m-1)
//             return t[i][j] = grid[i][j] + solve(i, j+1, m, n, grid);
//         else if(j == n-1)
//             return t[i][j] = grid[i][j] + solve(i+1, j, m, n, grid);
//         else
//             return t[i][j] = grid[i][j] + min(solve(i, j+1, m, n, grid), solve(i+1, j, m, n, grid));
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         memset(t, -1, sizeof(t));
//         return solve(0, 0, m, n, grid);

//     }
// };


class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>t(m, vector<int>(n));
        t[0][0] = grid[0][0];
        for(int col = 1; col < n; col++){
            t[0][col] = t[0][col-1] + grid[0][col];
        }
        for(int row = 1; row < m; row++){
            t[row][0] = t[row-1][0] + grid[row][0];
        }


        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                t[row][col] = grid[row][col] + min(t[row-1][col], t[row][col-1]);
            }
        }
        return t[m-1][n-1];

    }   
};