class Solution {
public:
    void updateTree(vector<int>& segmentTree, int l, int r, int i, int updateVal){
        if(l == r){
            segmentTree[i] = 1;
            return;
        }

        int mid = l + (r - l)/2;
        if(updateVal <= mid){
            updateTree(segmentTree, l, mid, 2*i+1, updateVal);
        }
            
        else{
            updateTree(segmentTree, mid+1, r, 2*i+2, updateVal);
        }
            

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];

    }

    long long query(vector<int>& segmentTree, int l, int r, int i, int st, int en){
        if(en < l || st > r){
            return 0;
        }

        if(st <= l && r <= en){
            return segmentTree[i]; 
        }

        int mid = l + (r - l)/2;
        
        long long left = query(segmentTree, l, mid, 2*i+1, st, en);
        long long right = query(segmentTree, mid+1, r, 2*i+2, st, en);

        return left + right;

    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        unordered_map<int, int> um;

        for(int i = 0; i < N; i++){
            um[nums2[i]] = i;
        }

        vector<int> segmentTree(4*N, 0);

        updateTree(segmentTree, 0, N-1, 0, um[nums1[0]]);

        long long result = 0;
        for(int i = 1; i < N; i++){
            int idx = um[nums1[i]];
            long long leftCommonCount = query(segmentTree, 0, N-1, 0, 0, idx);
            long long leftNotCommonCount = i - leftCommonCount;
            long long elementsAfternums2 = (N - 1) - idx;
            long long rightCommonCount = elementsAfternums2 - leftNotCommonCount;
            result += leftCommonCount * rightCommonCount;

            updateTree(segmentTree, 0, N-1, 0, idx);

        }
        return result;

    }
};