class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());

        // low will always be 0 because we are trying to make 2 elements similar
        //high will changes and there are 3 possibilities for it

        return min({ 
            nums[N-3] - nums[0],
            nums[N-1] - nums[2],
            nums[N-2] - nums[1]   // we tried to increase min and decrease max
        });

    }
};