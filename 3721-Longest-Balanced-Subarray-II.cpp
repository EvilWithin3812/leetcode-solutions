
// Brute force
//  time limit exceeding you have to use segment tree instade of those nested
//  for loops
// because those loops are adding val in range or subtracting them

// class Solution {
// public:
//     int longestBalanced(vector<int>& nums) {
//         int N = nums.size();

//         vector<int> cumSum(N, 0);

//         unordered_map<int, int> um;
//         int maxCount = 0;

//         for(int r = 0; r < N; r++){
//             int prev = -1;
//             int val = nums[r] % 2 == 0 ? 1 : -1;
//             if(um.count(nums[r]))
//                 prev = um[nums[r]];

//             if(prev != -1){
//                 for(int i = 0; i <= prev; i++){
//                     cumSum[i] = cumSum[i] - val;
//                 }
//             }

//             for(int l = 0; l <= r; l++){
//                 cumSum[l] = cumSum[l] + val;
//             }

//             for(int l = 0; l <= r; l++){
//                 if(cumSum[l] == 0){
//                     maxCount = max(maxCount, r-l+1);
//                     break;
//                 }
//             }

//             um[nums[r]] = r;
//         }

//         return maxCount;

//     }
// };


//lazy tree propagation

class Solution {
public:
    int N;
    vector<int> segmentTreeMin;
    vector<int> segmentTreeMax;
    vector<int> lazy;

    int findLeftMostZero(int i, int l, int r) {
        propagate(i, l, r);
        if (segmentTreeMin[i] > 0 || segmentTreeMax[i] < 0)
            return -1;

        if (l == r)
            return l;

        int mid = l + (r - l) / 2;
        int leftResult = findLeftMostZero(2 * i + 1, l, mid);
        if (leftResult != -1)
            return leftResult;

        return findLeftMostZero(2 * i + 2, mid + 1, r);
    }

    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segmentTreeMin[i] += lazy[i];
            segmentTreeMax[i] += lazy[i];

            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        propagate(i, l, r);
        if (l > end || r < start)
            return;

        if (l >= start && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);
        segmentTreeMin[i] =
            min(segmentTreeMin[2 * i + 1], segmentTreeMin[2 * i + 2]);
        segmentTreeMax[i] =
            max(segmentTreeMax[2 * i + 1], segmentTreeMax[2 * i + 2]);
    }

    int longestBalanced(vector<int>& nums) {
        N = nums.size();
        segmentTreeMin.assign(4*N, 0);
        segmentTreeMax.assign(4*N, 0);
        lazy.assign(4*N, 0);



        vector<int> cumSum(N, 0);
        int maxCount = 0;
        unordered_map<int, int> um;

        for (int r = 0; r < N; r++) {
            int val = nums[r] % 2 == 0 ? 1 : -1;

            int prev = -1;
            if (um.count(nums[r]))
                prev = um[nums[r]];

            if (prev != -1) {
                updateRange(0, prev, 0, 0, N - 1, -val);
            }

            updateRange(0, r, 0, 0, N - 1, val);

            int l = findLeftMostZero(0, 0, N - 1);
            if (l != -1)
                maxCount = max(maxCount, r - l + 1);

            um[nums[r]] = r;
        }

        return maxCount;
    }
};