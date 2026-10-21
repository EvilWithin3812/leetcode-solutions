class Solution {
public:
    int minOperations(string s) {
        int N = s.size();
        if(is_sorted(s.begin(), s.end()))
            return 0;

        if(N==2)
            return -1;

        
        char min_ch = *min_element(s.begin(), s.end());
        char max_ch = *max_element(s.begin(), s.end());

        if(s[0] == min_ch || s[N-1] == max_ch)
            return 1;

        char mid_min_ch = *min_element(s.begin()+1, s.end()-1);
        char mid_max_ch = *max_element(s.begin()+1, s.end()-1);

        if(s[0] > mid_max_ch && s[N-1] < mid_min_ch)
            return 3;
        
        return 2;

    }
};