class Solution {
public:
    int t[2501][2501];

    int solve(vector<int>& nums, int i, int p, int N) {
        if (i == N)
            return 0;


        if(p != -1 && t[i][p] != -1)
            return t[i][p];

        //take it
        int take = 0;
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(nums, i+1, i, N);
        }

        //dont take it
        int skip = solve(nums, i+1, p, N);

        if(p != -1)
            t[i][p] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int N = nums.size();
        return solve(nums, 0, -1, N);
    }
};