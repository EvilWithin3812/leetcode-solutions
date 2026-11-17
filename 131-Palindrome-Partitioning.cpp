class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(string& s, int idx, vector<string>& curr,
               vector<vector<string>>& ans, int N) {

        if (idx == N) {
            ans.push_back(curr);
            return;
        }

        for (int j = idx; j < N; j++) {
            if(isPalindrome(s, idx, j)){
                curr.push_back(s.substr(idx, j - idx + 1));
                solve(s, j+1, curr, ans, N);
                curr.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int N = s.size();

        solve(s, 0, curr, ans, N);

        return ans;
    }
};