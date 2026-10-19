// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int N = pairs.size();

//         auto lambda = [](vector<int>& p1, vector<int>& p2){
//             return p1[1] < p2[1];
//         };

//         sort(pairs.begin(), pairs.end(), lambda);

//         int p1 = pairs[0][0];
//         int p2 = pairs[0][1];
//         int count = 1;
//         for(int i = 1; i < N; i++){
//             if(p2 < pairs[i][0]){
//                 count++;
//                 p2 = pairs[i][1];
//             }
//         }

//         return count;

//     }
// };


class Solution {
public:
    int t[1001][1001];

    int solve(vector<vector<int>>& pairs, int i, int N, int prev){
        if(i == N){
            return 0;
        }

        if(prev != -1 && t[i][prev] != -1)
            return t[i][prev];


        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(pairs, i+1, N, i);
        }

        int skip = solve(pairs, i+1, N, prev);

        if(prev != -1)
            t[i][prev] = max(take, skip);

        return max(take, skip); 

    }


    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        int N = pairs.size();
        sort(pairs.begin(), pairs.end());
        int ans = solve(pairs, 0, N, -1);
        return ans;
    }
};