class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int i, int n){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];
        //take
        int take = nums[i] + solve(nums, i+2, n);

        //dont take
        int skip = solve(nums, i+1, n);

        return t[i] = max(take, skip);

    }

    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int N = nums.size();
        return solve(nums, 0, N);
    }
};