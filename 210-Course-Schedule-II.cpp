// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         int N = numCourses;
//         vector<int> inDegree(N, 0);
//         unordered_map<int, vector<int>> um;
//         for(auto v : prerequisites){
//             int a = v[0];
//             int b = v[1];

//             um[b].push_back(a);
//             inDegree[a]++;
//         }

//         queue<int> q;
//         for(int i = 0; i < N; i++){
//             if(inDegree[i] == 0){
//                 q.push(i);
//             }
//         }

//         vector<int> ans;
//         int count = 0;

//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();
//             ans.push_back(curr);
//             count++;

//             for(auto xd : um[curr]){
//                 inDegree[xd]--;
//                 if(inDegree[xd] == 0){
//                     q.push(xd);
//                 }
//             }
//         }

//         if(count != numCourses){
//             ans.clear();
//         }
//         return ans;
//     }
// };


class Solution {
public:
    bool isCycle(unordered_map<int, vector<int>>& um, stack<int>& st, vector<bool>& inRecursion, vector<bool>& visited, int i){
        visited[i] = true;
        inRecursion[i] = true;

        for(auto xd : um[i]){
            if(!visited[xd]){
                if(isCycle(um, st, inRecursion, visited, xd)){
                    return true;
                }
            }
            else if(inRecursion[xd] == true){
                return true;
            }

        }
        inRecursion[i] = false;
        st.push(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<bool>inRecursion(N, false);
        vector<bool>visited(N, false);

        unordered_map<int, vector<int>> um;
        for(auto v : prerequisites){
            int a = v[0];
            int b = v[1];

            um[b].push_back(a);
        }
        
        vector<int> ans;
        stack<int> st;
        
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                if(isCycle(um, st, inRecursion, visited, i)){
                   return {};
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};