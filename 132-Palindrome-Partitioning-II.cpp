// class Solution {
// public:
//     int t[2001][2001];

//     bool isPalindrome(string& s, int l, int r){
//         while(l <= r){
//             if(s[l] != s[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }

//     int solve(string& s, int i, int j){

//         if(i >= j)
//             return 0;

//         if(t[i][j] != -1)
//             return t[i][j];
        
//         if(isPalindrome(s, i, j)){
//             return 0;
//         }

        

//         int cuts = INT_MAX;
//         for(int k = i; k <= j-1; k++){
//             int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
//             cuts = min(cuts, temp);
            
//         }

//         return t[i][j] = cuts;

//     }


//     int minCut(string s) {
//         memset(t, -1, sizeof(t));
//         int N = s.size();
//         return solve(s, 0, N-1);
        
//     }
// };

class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        vector<vector<bool>> t(N, vector<bool>(N,false));

        for(int i = 0; i < N; i++){
            t[i][i] = true;
        }

        for(int L = 2; L <= N; L++){
            for(int i = 0; i < N-L+1 ; i++){
                int j = i + L - 1;

                if(L == 2){
                    t[i][j] =  (s[i] == s[j]);
                }
                else{
                    t[i][j] = (s[i] == s[j]) && t[i+1][j-1];
                }
            }
        }

        vector<int> dp(N);
        for(int i = 0; i < N; i++){
            if(t[0][i] == true){
                dp[i] = 0;
            }
            else{
                dp[i] = INT_MAX;
                for(int k = 0; k < i; k++){
                    if(t[k+1][i] == true && 1 + dp[k] < dp[i]){
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }
        return dp[N-1];
        
    }
};

