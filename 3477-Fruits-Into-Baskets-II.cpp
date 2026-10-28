class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = fruits.size();

        int count = 0;
        for(int i = 0; i < N; i++){
            bool placed = false;
            for(int j = 0; j < N; j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = -1;
                    placed = true;
                    break;
                }
            }
            if(!placed)
                count++;
        }

        return count;

    }
};