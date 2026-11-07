class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        auto lambda = [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        };
        sort(logs.begin(), logs.end(), lambda);

        vector<pair<int, int>> temp(queries.size());
        for(int i = 0; i < queries.size(); i++){
            temp[i].first = queries[i];
            temp[i].second = i;
        }

        auto xd = [](pair<int, int>& p1, pair<int, int>& p2){
            return p1.first < p2.first;
        };

        sort(temp.begin(), temp.end(), xd);

        unordered_map<int, int> um;

        vector<int> ans(queries.size());
        

        int i = 0;
        int j = 0;

        for(int z = 0; z < temp.size(); z++){
            int leftRange = temp[z].first - x;
            int rightRange = temp[z].first;

            while(j < logs.size() && logs[j][1] <= rightRange){
                um[logs[j][0]]++;
                j++; 
            }

            while(i < logs.size() && logs[i][1] < leftRange){
                um[logs[i][0]]--;
                if(um[logs[i][0]]  == 0){
                    um.erase(logs[i][0]);
                }
                i++;
            }

            ans[temp[z].second] = n - um.size();
        }

        
        return ans;
    }
};