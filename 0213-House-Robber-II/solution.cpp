class Solution {
public:
    long long solve(vector<int>& nums, bool flag, int i, int N){
        if(i == N){
            return 0;
        }


        //take it
        long long val = nums[i];
        if(flag == false){
            val = -val;
        }
        long long take = val + solve(nums, !flag, i+1, N);

        //dont take it

        long long skip = solve(nums, flag, i+1, N);

        return max(take, skip);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        int N = nums.size();
        return solve(nums, true, 0, N);
        
    }
};