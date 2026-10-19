class Solution {
public:

    int t[301][11];

    int solve(vector<int>& nums, int i, int d, int N){
        if(d == 1){
            int maxi = nums[i];
            for(int idx = i; idx < N; idx++){
                maxi = max(nums[idx], maxi);
            }
            return maxi;
        }
        if(t[i][d] != -1)
            return t[i][d];

        
        int finalResult = INT_MAX;
        int maxi = 0;
        for(int idx = i; idx <= N-d; idx++){
            maxi = max(maxi, nums[idx]);
            int take = maxi + solve(nums, idx+1, d-1, N); 

            finalResult = min(finalResult, take);

        }


        return t[i][d] = finalResult;

    }
    

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(t, -1, sizeof(t));
        int N = jobDifficulty.size();
        if(N < d) 
            return -1;
        return solve(jobDifficulty, 0, d, N);
    }
};