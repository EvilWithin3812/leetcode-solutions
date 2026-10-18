class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int N){
        if(i > N) return 0;

        if(t[i] != -1) return t[i];

        int take = nums[i] + solve(nums, i+2, N);
        int skip = solve(nums, i+1, N);

        return t[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        memset(t, -1, sizeof(t));
        int N = nums.size();
        if(N == 1)
            return nums[0];
        if(N == 2)
            return max(nums[0], nums[1]);

        int firstCase = solve(nums, 0, N-2);

        memset(t, -1, sizeof(t));
        int secondCase = solve(nums, 1, N-1);

        return max(firstCase, secondCase);

        
        
    }
};