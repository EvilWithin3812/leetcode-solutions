//brute force solution

// class Solution {
// public:
//     bool isValid(string& s1, string& s2){
//         if(s1.size() != s2.size() + 1)
//             return false;
        
//         int i = 0;
//         int j = 0;
//         while(i < s1.size() && j < s2.size()){
//             if(s1[i] == s2[j]){
//                 j++;
//             }
//             i++;
//         }

//         return j == s2.size();
//     }

//     int longestStrChain(vector<string>& words) {
//         int N = words.size();

//         auto lambda = [](string& v1, string& v2){
//             return v1.size() < v2.size();
//         };

//         sort(words.begin(), words.end(), lambda); 
//         vector<int> dp(N, 1);
//         int ans = 1;
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < i; j++){
//                 if(isValid(words[i], words[j])){
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             ans = max(dp[i], ans);
//         }

//         return ans;
//     }
// };


//i wanted to do this question with dp so lets do using that
int t[1001][1001];

class Solution {
public:
    bool isValid(string& s1, string& s2){
        if(s1.size() != s2.size() + 1)
            return false;
        
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                j++;
            }
            i++;
        }

        return j == s2.size();
    }

    int solve(vector<string>& words, int i , int prev){
        if(i == words.size()){
            return 0;
        }


        if(prev != -1){
            if(t[i][prev] != -1)
            return t[i][prev];
        }

        int take = 0;
        if(prev == -1 || isValid(words[i], words[prev])){
            take = 1 + solve(words, i+1, i);
        }

        int skip = solve(words, i+1, prev);
        if(prev != -1){
            t[i][prev] = max(take, skip);
        }


        return max(take, skip);

    }



    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        int N = words.size();

        auto lambda = [](string& v1, string& v2){
            return v1.size() < v2.size();
        };

        sort(words.begin(), words.end(), lambda); 

        return solve(words, 0, -1);


        
    }
};