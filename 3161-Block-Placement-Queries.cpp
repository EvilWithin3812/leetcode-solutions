//brute force solution of the problem

// class Solution {
// public:
//     vector<bool> getResults(vector<vector<int>>& queries) {
//         set<int> st;
//         vector<bool> ans;
//         int N = queries.size();

//         for(int i = 0; i < N; i++){
//             if(queries[i][0] == 1){
//                 st.insert(queries[i][1]);
//             }
//             else{
//                 int x = queries[i][1];
//                 int sz = queries[i][2];
//                 int prev = 0;
//                 bool found = false;

//                 for(int curr : st){
//                     if(curr > x)
//                         break;
//                     if(curr - prev >= sz){
//                         found = true;
//                         break;
//                     }
//                     prev = curr;
//                 }

//                 if(!found){
//                     found = x - prev >= sz;
//                 }
//                 ans.push_back(found);

//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:

    int querySegment(int start, int end, int i, int l, int r, vector<int>& segmentTree){
        if(l > end || r < start)
            return 0;
        if(start <= l && r <= end){
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;

        return max(querySegment(start, end, 2*i+1, l, mid, segmentTree), querySegment(start, end, 2*i+2, mid+1, r, segmentTree));
    }

    void update(int idx, int val, int i, int l, int r, vector<int>& segmentTree){
        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l +(r-l)/2;
        if(idx <= mid)
            update(idx, val, 2*i+1, l, mid, segmentTree);
        else
            update(idx, val, 2*i+2, mid+1, r, segmentTree);

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);

    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = 50000;
        vector<int>segmentTree(4*N, 0);
        set<int> st;
        st.insert(0);
        vector<bool> ans;

        for(auto& query : queries){
            if(query[0] == 1){
                int x = query[1];
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);
                update(x, x-pre, 0, 0, N-1, segmentTree);
                update(nxt, nxt-x, 0, 0, N-1, segmentTree);
                st.insert(x);
            }

            else{
                int x = query[1];
                int sz = query[2];
                auto it = st.upper_bound(x);
                int pre =  *prev(it);
                int maxGap = querySegment(0, pre, 0, 0, N-1, segmentTree);
                int best = max(maxGap, x-pre);

                ans.push_back(best >= sz);
            }
        }

        return ans;


    }
};