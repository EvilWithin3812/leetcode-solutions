//the code i wrote but its giving TLE because of calculating preCalc vector
// so in next code we have fixed it using multiset

// class Solution {
// public:
//     long long t[100001][16];

//     long long solve(vector<int>& nums, int i, int j) {
//         vector<long long> temp(nums.begin() + i, nums.begin() + j + 1);
//         sort(temp.begin(), temp.end());
//         int N = temp.size();
//         long long median = temp[N / 2];

//         long long ans = 0;
//         for (long long x = i; x < j + 1; x++) {
//             ans += llabs(median - nums[x]);
//         }
//         return ans;
//     }

//     long long recur(vector<int>& nums, int i, int N, int L, int count, vector<long long>& preCalc) {
        
//         if(count == 0){
//             return 0;
//         }
        
//         if(t[i][count] != -1){
//             return t[i][count];
//         }

//         if (N - i < count * L) {
//             return LLONG_MAX;
//         }
        
//         long long take = recur(nums, i + L, N, L,  count-1, preCalc);
//         if(take != LLONG_MAX)
//             take += preCalc[i];

//         long long skip = recur(nums, i+1, N, L, count, preCalc);

//         return t[i][count] = min(take, skip);
//     }

//     long long minOperations(vector<int>& nums, int x, int k) {
//         int N = nums.size();
//         memset(t, -1, sizeof(t));
//         vector<long long> preCalc(N - x + 1);
//         for (int i = 0; i + x - 1 < N; i++) {
//             int j = i + x - 1;
//             preCalc[i] = solve(nums, i, j);
//         }
        
//         long long ans = recur(nums, 0, N, x, k, preCalc);
//         return ans;

//     }
// };


class Solution {
public:
    long long t[100001][16];

    long long recur(vector<int>& nums, int i, int N, int L, int count, vector<long long>& preCalc) {
        
        if(count == 0){
            return 0;
        }
        
        if(t[i][count] != -1){
            return t[i][count];
        }

        if (N - i < count * L) {
            return LLONG_MAX;
        }
        
        long long take = recur(nums, i + L, N, L,  count-1, preCalc);
        if(take != LLONG_MAX)
            take += preCalc[i];

        long long skip = recur(nums, i+1, N, L, count, preCalc);

        return t[i][count] = min(take, skip);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int N = nums.size();
        memset(t, -1, sizeof(t));
        vector<long long> preCalc(N - x + 1);
        
        int i = 0;
        int j = 0;
        multiset<int> left;
        multiset<int> right;
        long long leftSum = 0;
        long long rightSum = 0;

        while(j < N){
            if(left.size() <= right.size()){
                left.insert(nums[j]);
                leftSum += nums[j];
            }
            else{
                right.insert(nums[j]);
                rightSum += nums[j];
            }


            //balancing 
            if(!left.empty() && !right.empty()){
                int left_max = *left.rbegin();
                int right_min = *right.begin();

                if(left_max > right_min){
                    left.erase(left.find(left_max));
                    right.erase(right.find(right_min));

                    left.insert(right_min);
                    right.insert(left_max);

                    leftSum = leftSum + right_min - left_max;
                    rightSum = rightSum + left_max - right_min;

                }
            }

            if(j - i + 1 == x){
                long long median = *left.rbegin();
                long long leftSize = left.size();
                long long rightSize = right.size();

                preCalc[i] = (leftSize * median - leftSum) + (rightSum - rightSize * median);
                if(left.find(nums[i]) != left.end()){
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                }
                else{
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }
            j++;
        }
        
        long long ans = recur(nums, 0, N, x, k, preCalc);
        return ans;

    }
};