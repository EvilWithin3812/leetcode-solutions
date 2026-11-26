class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob  = 9;
        int count = 0;
        while(n >= 0){
            if(count % 2 == 0){
                n = n - alice;
                if(n < 0){
                    return false;
                }
                count++;
                alice = alice - 2;
            }
            else{
                n = n - bob;
                count++;
                bob = bob - 2;
            }
        }

        return true;
    }
};