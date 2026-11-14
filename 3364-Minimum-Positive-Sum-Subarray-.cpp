class Solution {
public:



    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        
        int mini = INT_MAX;
        
        for(int i = 0; i < N; i++){
            int curr = 0;
            for(int j = i; j < N; j++){
                int size = j - i + 1;
                curr += nums[j];
                if(l <= size && size <= r && curr > 0){
                    mini = min(mini, curr);
                    
                }
            }
        }
        if(mini  == INT_MAX)
            return -1;

        return mini;


    }
};