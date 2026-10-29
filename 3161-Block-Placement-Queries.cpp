class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> st;
        vector<bool> ans;
        int N = queries.size();

        for(int i = 0; i < N; i++){
            if(queries[i][0] == 1){
                st.insert(queries[i][1]);
            }
            else{
                int x = queries[i][1];
                int sz = queries[i][2];
                int prev = 0;
                bool found = false;

                for(int curr : st){
                    if(curr > x)
                        break;
                    if(curr - prev >= sz){
                        found = true;
                        break;
                    }
                    prev = curr;
                }

                if(!found){
                    found = x - prev >= sz;
                }
                ans.push_back(found);

            }
        }

        return ans;
    }
};