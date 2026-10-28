class NumArray {
public:
    int N;
    vector<int> segmentTree;
    vector<int> lazy;

    NumArray(vector<int>& nums) {
        N = nums.size();
        segmentTree.resize(4*N, 0);
        buildTree(0, N-1, 0, nums);
        lazy.resize(4*N, 0);

    }

    void buildTree(int l, int r, int i, vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l)/2;
        buildTree(l, mid, 2*i+1, nums);
        buildTree(mid+1, r, 2*i+2, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    
    
    void updateTree(int index, int val, int l, int r, int i){
        if(lazy[i] != 0){
            
        }

        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l)/2;

        if(index <= mid){
            updateTree(index, val, l, mid, 2*i+1);
        }
        else{
            updateTree(index, val, mid+1, r, 2*i+2);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void update(int index, int val) {
        updateTree(index, val, 0, N-1, 0);
    }
    int query(int left, int right, int l, int r, int i){ // given (left, right, (my indexes))
        if(left > r || right < l){
            return 0;
        }

        if(l >= left && r <= right){
            return segmentTree[i];
        }
        int mid = l + (r - l)/2;
        return query(left, right, l, mid, 2*i+1) +
                query(left, right, mid+1, r, 2*i+2);

    }

    int sumRange(int left, int right) {
        return query(left, right, 0, N-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */