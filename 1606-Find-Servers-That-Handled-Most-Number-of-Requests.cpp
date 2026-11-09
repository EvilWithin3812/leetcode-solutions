class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int N = arrival.size();
        vector<int> ans;

        set<int> st;
        for(int i = 0; i < k; i++){
            st.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unavai;
        
        //thinking to store servers frequency in map
        vector<int> v(N, 0);

        int i = 0;
        while(i < N){
            int neededServer = i % k;

            if(!unavai.empty()){
                while(!unavai.empty() && unavai.top().first <= arrival[i]){
                   st.insert(unavai.top().second);
                   unavai.pop();
                }
            }

            if(!st.empty()){
                auto it = st.lower_bound(neededServer);
                if(it == st.end()){
                    it = st.begin();
                }
                v[*it]++;
                unavai.push({(arrival[i] + load[i]), *it});
                st.erase(it);
                
            }
            i++;
        }

        int maxi = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > maxi){
                maxi = v[i];
            }
        }

        for(int i = 0;i < v.size(); i++){
            if(v[i] == maxi){
                ans.push_back(i);
            }
        }

        

        return ans;
    }
};