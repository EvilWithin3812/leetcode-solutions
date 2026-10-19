class Solution {
public:
    void buildTree(vector<int>& segmentTree, vector<int>& heights, int i, int l, int r){
        if(l == r){
            segmentTree[i] = l;
            return;
        }
        
        int mid = l + (r - l)/2;

        buildTree(segmentTree, heights, 2*i+1, l, mid);
        buildTree(segmentTree, heights, 2*i+2, mid+1, r);

        int leftIdx = segmentTree[2*i+1];
        int rightIdx = segmentTree[2*i+2];

        segmentTree[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int query(vector<int>& segmentTree, int i, int start, int end, int l, int r){
        if(end < l || start > r){
            return -1;
        }

        if(start <= l && end >= r){
            return segmentTree[i];
        }

        int mid = l + (r - l)/2;

        int leftIdx = query(segmentTree, 2*i+1, start, end, l, mid);
        int rightIdx = query(segmentTree, 2*i+2, start, end, mid+1, r);

        if(leftIdx == -1) return rightIdx;
        if(rightIdx == -1) return leftIdx; 

        if(segmentTree[leftIdx] >= segmentTree[rightIdx])
            return leftIdx;
        
        return rightIdx;
    }


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int N = heights.size();
        vector<int> segmentTree(4 * N);
        vector<int> ans;
        buildTree(segmentTree, heights, 0, 0, N-1);

        for(int i = 0; i < queries.size(); i++){
            int maxi = max(queries[i][0], queries[i][1]);

            int check = query(segmentTree, 0, queries[i][1]+1, N-1, 0, N-1);
            cout << check << endl;
            int left = queries[i][1] + 1;
            int right = N-1;


        }

        return ans;


        

    }
};