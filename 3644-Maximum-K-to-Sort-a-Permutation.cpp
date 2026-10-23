class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int N = nums.size();
        int k = -1;
        for(int i = 0; i < N; i++){
            if(nums[i] != i){
                k = (nums[i] & k);
            }
        }

        return k == -1 ? 0 : k;
        

    }
};