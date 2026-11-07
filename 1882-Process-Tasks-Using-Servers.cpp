class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> ava;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> unava;

        for(int i = 0; i < servers.size(); i++){
            ava.push({servers[i], i});
        }

      
        vector<int> ans;
        int count = 0;
        long long t = 0;

        while(count != tasks.size()){
            t = max(t, (long long) count);
            if(!unava.empty() && t >= get<0>(unava.top())){
                while(!unava.empty() && t >= get<0>(unava.top())){
                    ava.push({get<1>(unava.top()), get<2>(unava.top())});
                    unava.pop();
                }
                
            }

            if(!ava.empty()){
                int currServerIdx = ava.top().second;
                int currServerWt = ava.top().first;

                ava.pop();
                ans.push_back(currServerIdx);
                unava.push({t+tasks[count], currServerWt, currServerIdx});
                count++;
            }

            else{
                t = get<0>(unava.top());
                while(!unava.empty() && get<0>(unava.top()) <= t){
                    ava.push({get<1>(unava.top()), get<2>(unava.top())});
                    unava.pop();
                }
            }
        }
            

            
         

        return ans;
    }
};