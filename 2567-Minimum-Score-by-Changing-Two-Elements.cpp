// class Solution {
// public:
//     int minimizeSum(vector<int>& nums) {
//         int N = nums.size();
//         sort(nums.begin(), nums.end());

//         // low will always be 0 because we are trying to make 2 elements similar
//         //high will changes and there are 3 possibilities for it

//         return min({ 
//             nums[N-3] - nums[0],
//             nums[N-1] - nums[2],
//             nums[N-2] - nums[1]   // we tried to increase min and decrease max
//         });

//     }
// };

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int s1 = INT_MAX;
        int s2 = INT_MAX;
        int s3 = INT_MAX;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int l3 = INT_MIN;


        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[i] < s1){
                s3 = s2;
                s2 = s1;
                s1 = nums[i];
            }
            else if(nums[i] < s2){
                s3 = s2;
                s2 = nums[i];
            }
            else if(nums[i] < s3){
                s3 = nums[i];
            }


            if(nums[i] > l1){
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            }
            else if(nums[i] > l2){
                l3 = l2;
                l2 = nums[i];
            }
            else if(nums[i] > l3){
                l3 = nums[i];
            }
        }

        return min({
            l1 - s3,
            l3 - s1,
            l2 - s2
        });

    }
};