//this code is giving TLE
//you need to use bottom up for this code 


// class Solution {
// public:
//     int t[1001][1001];

//     int solve(vector<int>& nums, vector<int>& ans, int i, int prev, vector<int>& temp){
//         if(i == nums.size()){
//             if(temp.size() > ans.size()){
//                 ans = temp;
//             }
//             return 0;
//         }
//         if(prev != -1 &&t[i][prev] != -1)
//             return t[i][prev];


//         int take = 0;
//         if(prev == -1 || nums[i] % nums[prev] == 0){
//             temp.push_back(nums[i]);
//             take = 1 + solve(nums, ans, i+1, i, temp);
//             temp.pop_back();
//         }

//         int skip = solve(nums, ans, i+1, prev, temp);

//         if(prev != -1)
//             t[i][prev] = max(take, skip);
        
//         return max(take, skip);

//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         memset(t, -1, sizeof(t));
//         vector<int>ans;
//         vector<int> temp;
//         solve(nums, ans, 0, -1, temp);

//         return ans;

//     }
// };


//bottom  up
//time complexity O(n^2)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();

        vector<int> dp (N, 1);
        vector<int> prevIdx(N, -1);

        int maxIdx = 1;
        int lastChosenIdx = 0;
        for(int i = 1; i < N; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        prevIdx[i] = j;
                    }
                    if(dp[i] > maxIdx){
                        maxIdx = dp[i];
                        lastChosenIdx = i;

                    }
                    
                }
            }
        }

        vector<int>result;
        while(lastChosenIdx >= 0){
            result.push_back(nums[lastChosenIdx]);
            lastChosenIdx = prevIdx[lastChosenIdx];
        }

        return result;
       

    }
};