//memoization + recursion code

// class Solution {
// public:
//     int t[101][101];

//     int solve(int i, int j, int m, int n){
//         if(i == m-1  && j == n-1)
//             return 1;
        
//         if(i == m || j == n)
//             return 0;

//         if(t[i][j] != -1)
//             return t[i][j];
        
//         int right = solve(i, j+1, m, n);
//         int down = solve(i+1, j, m, n);

//         return t[i][j] = right + down;

//     }

//     int uniquePaths(int m, int n) {
//         memset(t, -1, sizeof(t));
//         int ans = solve(0, 0, m, n);
//         return ans;
//     }
// };


//ill do it with bottom up now

class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> t(m, vector<int>(n));
        
        t[0][0] = 1;

        for(int row = 1; row < m; row++){
            t[row][0] = 1;
        }

        for(int col = 1; col < n; col++){
            t[0][col] = 1;
        }


        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                t[row][col] = t[row-1][col] + t[row][col-1];
            }
        }
        return t[m-1][n-1];

    }
};