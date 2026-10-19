class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int N = nums.size();

        int smallNums = 0;
        int equalTar = 0;

        for(int i = 0; i < N; i++){
            if(nums[i] < target)
                smallNums++;
            
            if(nums[i] == target)
                equalTar++;
        }
        for(int i = smallNums; i < smallNums + equalTar; i++){
            ans.push_back(i);
        }
        return ans;
        
    }
};