class Solution {
public:
    bool checkString(string s) {
        int firstB = -1;
        int lastA = -1;

        bool Bfound = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                lastA = i;
            }
            else if(s[i] == 'b' && Bfound == false){
                firstB = i;
                Bfound = true;
            }
        }

        if(firstB == -1)
            return true;
        
        if(firstB > lastA)
            return true;

        return false;


    }
};