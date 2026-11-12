class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingCount = 0;
        int decreasingCount = 0;
        int N = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MIN;

        int prev = 0;
        int prev2 = INT_MAX;
        for(int i = 0; i < N; i++){
            if(nums[i] > prev){
                prev = nums[i];
                increasingCount++;
                maxi = max(maxi, increasingCount);
            }
            else{
                prev = 0;
                increasingCount = 0;
                if(nums[i] > prev){
                    increasingCount++;
                }
                prev = nums[i];
            }


            if(nums[i] < prev2){
                prev2 = nums[i];
                decreasingCount++;
                mini = max(mini, decreasingCount);
            }
            else{
                prev2 = INT_MAX;
                decreasingCount = 0;
                if(nums[i] < prev2){
                    decreasingCount++;
                }
                prev2 = nums[i];
            }
        }

        return max(maxi, mini);


        
    }
};