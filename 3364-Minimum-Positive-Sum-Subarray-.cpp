class Solution {
public:
    
    int find(vector<int>& nums, int i, int j){
        int curr = 0;
        for(int xd = i; xd <= j; xd++){
            curr += nums[xd];
        }

        return curr;
    }


    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        
        int mini = INT_MAX;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                int size = j - i + 1;
                if(l <= size && size <= r){
                    int check = find(nums, i, j);
                    if(check > 0)
                        mini = min(mini, check);
                    
                }
            }
        }
        if(mini  == INT_MAX)
            return -1;

        return mini;


    }
};