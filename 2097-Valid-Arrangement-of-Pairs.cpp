class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& um, int i, vector<int>& ans){
        while(!um[i].empty()){
            int xd = um[i].back();
            um[i].pop_back();
            dfs(um, xd, ans);
        }

        ans.push_back(i);
    }


    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int N = pairs.size();
        unordered_map<int, vector<int>> um;

        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;

        for(int i = 0; i < N; i++){
            um[pairs[i][0]].push_back(pairs[i][1]);
            outDegree[pairs[i][0]]++;
            inDegree[pairs[i][1]]++;
        }

        int src = pairs[0][0];
        vector<int> ans;

        bool checkEulerCircuit = true;
        for(auto& it : pairs){
            int first = it[0];
            if(outDegree[first] - inDegree[first] == 1){
                src = first;
                break;
            }
        }
        

        dfs(um, src, ans);
        reverse(ans.begin(), ans.end());

        vector<vector<int>> result;

        

        for(int i = 1; i < ans.size(); i++){
            result.push_back({ans[i-1], ans[i]});
        }
        
        return result;



    }
}; 