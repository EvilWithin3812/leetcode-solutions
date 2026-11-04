// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.length();
//         int count = 0;
//         vector<vector<bool>> t(n, vector<bool>(n, false));

//         for (int L = 1; L <= n; L++) {
//             for (int i = 0; i + L - 1 < n; i++) {
//                 int j = i + L - 1;

//                 if (i == j)
//                     t[i][j] = true;
//                 else if (i + 1 == j) {
//                     t[i][j] = (s[i] == s[j]);
//                 } else {
//                     t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
//                 }

//                 if (t[i][j] == true)
//                     count++;
//             }
//         }

//         return count;
//     }
// };

// recursion and memoisation
// int t[1001][1001];
// class Solution {
// public:
//     bool solve(string& s, int i, int j){
//         if(i > j){
//             return true;
//         }
//         if(t[i][j] != -1){
//             return t[i][j];
//         }
//         if(s[i] == s[j]){
//             return t[i][j] =  solve(s, i+1, j-1);
//         }

//         return t[i][j] = false;
//     }

//     int countSubstrings(string s) {
//         int N = s.size();
//         int count = 0;
//         memset(t, -1, sizeof(t));
//         for(int i = 0; i < N; i++){
//             for(int j = i; j < N; j++){
//                 if(solve(s, i, j)){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int count = 0;
        vector<vector<bool>> t(N, vector<bool>(N, false));

        for (int L = 1; L <= N; L++) {
            for (int i = 0; i+L-1 < N; i++) {
                int j = i + L - 1;

                if (i == j)
                    t[i][j] = true;
                else if (i + 1 == j)
                    t[i][j] = (s[i] == s[j]);
                else
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);

                if (t[i][j] == true) {
                    count++;
                }
            }
        }

        return count;
    }
};