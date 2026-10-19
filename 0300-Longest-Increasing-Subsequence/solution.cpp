class Solution {
public:
    int solve(vector<int>& nums, int i, int p, int N) {
        if (i == N)
            return 0;

        //take it
        int take = 0;
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(nums, i+1, i, N);
        }

        //dont take it
        int skip = solve(nums, i+1, p, N);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        return solve(nums, 0, -1, N);
    }
};