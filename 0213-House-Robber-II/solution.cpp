class Solution {
public:
    int t[2][10001];

    long long solve(vector<int>& nums, bool flag, int i, int N){
        if(i == N){
            return 0;
        }

        if(t[flag][i] != -1)
            return t[flag][i];

        //take it
        long long val = nums[i];
        if(flag == false){
            val = -val;
        }
        long long take = val + solve(nums, !flag, i+1, N);

        //dont take it

        long long skip = solve(nums, flag, i+1, N);

        return t[flag][i] = max(take, skip);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int N = nums.size();
        return solve(nums, true, 0, N);
        
    }
};