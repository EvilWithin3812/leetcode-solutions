// recursion

// class Solution {
// public:
//     int t[1001][1001];

//     int solve(string& s, int i, int j){
//         if(i > j)
//             return 0;;

//         if(i == j)
//             return 1;

//         if(t[i][j] != -1)
//             return t[i][j];

//         if(s[i] == s[j]){
//             return t[i][j] = 2 + solve(s, i+1, j-1);
//         }
        
//         return t[i][j] = max(solve(s,i+1, j), solve(s, i, j-1));
//     }


//     int longestPalindromeSubseq(string s) {
//         int N = s.size();
//         memset(t, -1, sizeof(t));
//         return solve(s, 0, N-1);
//     }
// };


//using bottom up

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> t(N, vector<int>(N, 0));

        for(int L = 1; L <= N; L++){
            for(int i = 0; i+L-1 < N ; i++){
                int j = i+L-1;

                if(L == 1)
                    t[i][j] = 1;

                else if(s[i] == s[j]){
                    t[i][j] = 2 + t[i+1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i+1][j]);
                }
            }
        }

        return t[0][N-1];
    }
};
