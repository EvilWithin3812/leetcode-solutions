class Solution {
public:
    string calc(string s) {
        int curr = 0;
        for (auto xd : s) {
            curr += (xd - '0');
        }

        return to_string(curr);
    }

    string digitSum(string s, int k) {
        int N = s.size();
        if (N <= k)
            return s;

        while (s.size() > k) {
            string curr = "";
            int i = 0;
            string temp = "";
            int j = 0;

            while(j < N){
                
                int size = j - i + 1;
                curr += s[j];
                if(size == k){
                    temp += calc(curr);
                    curr = "";
                    if(j+1 != N){
                        i = j+1;
                    }
                }
                if(j == N-1 && curr != ""){
                    temp += calc(curr);
                }
                j++;
            }

            s = temp;
            N = s.size();
        }

        return s;
    }
};