class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> inDegree(N, 0);
        unordered_map<int, vector<int>> um;
        for(auto v : prerequisites){
            int a = v[0];
            int b = v[1];

            um[b].push_back(a);
            inDegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i < N; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        int count = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            count++;

            for(auto xd : um[curr]){
                inDegree[xd]--;
                if(inDegree[xd] == 0){
                    q.push(xd);
                }
            }
        }

        if(count != numCourses){
            ans.clear();
        }
        return ans;
    }
};