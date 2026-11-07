// class Solution {
// public:
//     int t[1001][1001];

//     bool check(string& s, int i, int j){
//         if(i >= j)
//             return true;
        
//         if(t[i][j] != -1)
//             return t[i][j];
            
//         if(s[i] != s[j]){
//             return t[i][j] = false;
//         }

//         return t[i][j] = check(s, i+1, j-1);


//     }

//     string longestPalindrome(string s) {
//         memset(t, -1, sizeof(t));
//         int N = s.size();

//         int store_i = 0;
//         int maxLength = 0;
//         for(int i = 0; i < N; i++){
//             for(int j = i; j < N; j++){
//                 if(check(s, i, j)){
//                     if(j-i+1 > maxLength){
//                         store_i = i;
//                         maxLength = j-i+1;
//                     } 
//                 }
//             }
//         }

//         return s.substr(store_i, maxLength);
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<bool>> v(N, vector<bool>(N, false));
        int store_i = 0;
        int maxLength = 0;

        int count = 0;
        for(int L = 1; L <= N; L++){
            for(int i = 0; i+L-1 < N; i++){
                int j = i+L-1;
                if(L == 1){
                    v[i][j] = true;
                }
                    
                else if(L == 2){
                    v[i][j] = s[i] == s[j];
                }
                else{
                    v[i][j] = (s[i] == s[j] && v[i+1][j-1]);
                }


                if(v[i][j] == true && L > maxLength){
                    maxLength = L;
                    store_i = i;
                }   
            }
        }
        
        return s.substr(store_i, maxLength);
    }
};