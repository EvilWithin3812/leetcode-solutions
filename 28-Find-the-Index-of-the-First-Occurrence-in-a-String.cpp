// good solution but we will use KMP also because we need it in bigger problems

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int size = haystack.size() - needle.size() + 1;

//         for(int i = 0; i < size; i++){
//             string temp = haystack.substr(i, needle.size());
//             if(temp == needle)
//                 return i;
//         }

//         return -1;
//     }
// };



// we will solve this using KMP 


class Solution {
public:
    void calcLps(string& needle, vector<int>& LPS, int M){
        int len = 0;
        LPS[0] = 0;
        int i = 1;
        while(i < M){
            if(needle[i] == needle[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = LPS[len-1];
                else{
                    LPS[i] = 0;
                    i++;
                }
                   
            }
        }
    }

    int strStr(string haystack, string needle) {
        int N = haystack.length();
        int M = needle.length();
        vector<int>LPS(M, 0);
        calcLps(needle, LPS, M);
    
        int ans = -1;
        int i = 0;
        int j = 0;
        while(i < N){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == M){
                ans = i - M;
                return ans;
            }
            else if(i < N && haystack[i] != needle[j]){
                if(j != 0)
                    j = LPS[j-1];
                else{
                    i++;
                }
            }
        }

        return ans;

    }
};