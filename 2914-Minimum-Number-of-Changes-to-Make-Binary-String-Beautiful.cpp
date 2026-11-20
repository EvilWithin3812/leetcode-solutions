// class Solution {
// public:
//     int minChanges(string s) {
//         int N = s.size();
//         int changes = 0;
//         int curr = 0;
//         char ch = s[0];
//         for(int i = 0; i < N; i++){
//             if(s[i] == ch){
//                 curr++;
//                 continue;
//             }

//             if(curr % 2 == 0){
//                 curr = 1;
//             }
//             else{
//                 changes += 1;
//                 curr = 0;
//             }

//             ch = s[i];
//         }

//         return changes;


//     }
// };


class Solution {
public:
    int minChanges(string s) {
        int N = s.size();
        int changes = 0;
        
        for(int i = 0; i < N; i+=2){
            if(s[i] != s[i+1]){
                changes += 1;
            }
        }
        return changes;

    }
};