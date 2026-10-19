class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();

        auto lambda = [](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        };

        sort(pairs.begin(), pairs.end(), lambda);

        int p1 = pairs[0][0];
        int p2 = pairs[0][1];
        int count = 1;
        for(int i = 1; i < N; i++){
            if(p2 < pairs[i][0]){
                count++;
                p2 = pairs[i][1];
            }
        }

        return count;

    }
};