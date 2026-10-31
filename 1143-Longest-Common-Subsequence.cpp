
// recursion + memoization
// class Solution {
// public:
//     int t[1001][1001];
//     int solve(string& text1, string& text2, int i, int j){
//         if(i == text1.size() || j == text2.size())
//             return 0;

//         if(t[i][j] != -1)
//             return t[i][j];
        
//         if(text1[i] == text2[j]){
//             return t[i][j] = 1 + solve(text1, text2, i+1, j+1);
//         }

//         return t[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(t, -1, sizeof(t));
//         return solve(text1, text2, 0, 0);
//     }
// };


//bottom up approach

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int row = 0; row < m+1; row++){
            dp[row][0] = 0;
        }
        for(int col = 0; col < n+1; col++){
            dp[0][col] = 0;
        }

        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};