class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int N = arr.size();

        long long count = 0;
        long long oddCount = 0;
        long long evenCount = 0;
        vector<int> prefix (N);
        prefix[0] = arr[0];
        for(int i = 1; i < N; i++){
            prefix[i] = arr[i] + prefix[i-1];
        }

        

        for(int i = 0; i < N; i++){
            if(prefix[i] % 2 == 0){
                count = (count + oddCount) % MOD;
                evenCount++;
            }
            else{
                count = (count + 1 + evenCount) % MOD;
                oddCount++;
            }
        }

        return count;

    }
};