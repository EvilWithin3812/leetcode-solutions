class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int N = arrival.size();
        vector<int> ans;

        //we are gonna find the end times of arrival vector
        vector<int> endTime(N);
        for(int i = 0; i < N; i++){
            endTime[i] = arrival[i] + load[i];
        }


        for(auto c : endTime){
            cout << c << " ";
        }

        set<int> st;
        for(int i = 0; i < k; i++){
            st.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unavai;
        
        //thinking to store servers frequency in map
        map<int, int> mp;

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
                mp[*it]++;
                unavai.push({endTime[i], *it});
                st.erase(it);
                
            }
            i++;
        }

        int maxi = INT_MIN;
        for(const auto& xd : mp){
            if(xd.second > maxi){
                maxi = xd.second;
            }
        }

        for(const auto& xd : mp){
            if(xd.second == maxi){
                ans.push_back(xd.first);
            }
        }

        

        return ans;
    }
};