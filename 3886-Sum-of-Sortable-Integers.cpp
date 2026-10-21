class Solution {
public:
    void calcLps(vector<int>& nums, vector<int>& LPS, int N){
        int len = 0;
        LPS[0] = 0;
        int i = 1;

        while(i < N){
            if(nums[i] == nums[len]){
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

    bool kmpLogic(vector<int>& pat, vector<int>& nums){
        int N = nums.size();
        int M = pat.size();

        vector<int> LPS(N, 0);
        calcLps(nums, LPS, M);

        int i = 0;
        int j = 0;

        while(i < N){
            if(nums[i] == pat[j]){
                i++;
                j++;
            }

            if(j == M){
                return true;
            }

            else if(i < N && pat[j] != nums[i]){
                if(j != 0)
                    j = LPS[j-1];
                else{
                    i++;
                }
            }

        }

        return false;

    }

    bool isValid(vector<int>& v1, vector<int>& v2){
        vector<int> temp = v2;
        temp.insert(temp.end(), v2.begin(), v2.end());
        return kmpLogic(v1, temp);
    }



    int sortableIntegers(vector<int>& nums) {
        vector<int>sorted(nums);
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int result = 0;
        for(int i = 1; i <= nums.size(); i++){
            if(N % i != 0)
                continue;

            bool valid = true;
            for(int j = 0; j < N; j += i){
                vector<int> vec1(nums.begin() + j, nums.begin() + j + i);
                vector<int> vec2(sorted.begin() + j, sorted.begin() + j + i);

                if(!isValid(vec1, vec2)){
                    valid = false;
                    break;
                }
                
            }
            if(valid)
                result += i;
        }

        return result;
    }
};