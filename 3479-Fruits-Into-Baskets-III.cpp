class Solution {
public:

    void buildTree(int i, int l, int r, vector<int>& segmentTree, vector<int>& baskets){
        if(l == r){
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = l + (r - l)/2;
        buildTree(2*i+1, l, mid, segmentTree, baskets);
        buildTree(2*i+2, mid+1, r, segmentTree, baskets);

        segmentTree[i] = max(segmentTree[2*i+1] , segmentTree[2*i+2]); 
    }

    bool query(int i, int l, int r, vector<int>& segmentTree, int num){
        if(segmentTree[i] < num)
            return false;

        if(l == r){
            segmentTree[i] = -1;
            return true;
        }

        int mid = l + (r-l)/2;
        bool placed = false;
        if(segmentTree[2*i+1] >= num)
            placed = query(2*i+1, l, mid, segmentTree, num);
        else
            placed = query(2*i+2, mid+1, r, segmentTree, num);


        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
        return placed;
          
    }


    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = baskets.size();
        vector<int> segmentTree(4*N, -1);

        buildTree(0, 0, N-1, segmentTree, baskets);

        int count = 0;
        for(int i = 0; i < N; i++){
            if(!query(0, 0, N-1, segmentTree, fruits[i])){
                count++;
            }
        }

        return count;
            

    }
};