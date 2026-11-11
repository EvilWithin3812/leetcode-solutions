//time limit exceeding in thsi code i wrote myself 

// class Solution {
// public:
//     long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
//         long long ans = 0;
        
//         while(need1 > 0 || need2 > 0){
//             int min_cost = min(cost1 + cost2, costBoth);
//             int min_need = min(need1, need2);
            
//             if(min_cost == costBoth){
//                 if(min_need == need1){
//                     while(need1 > 0){
//                         ans += 1LL * costBoth;
//                         need1--;
//                         need2--;
//                     }
//                     if(need2 > 0){
//                         min_cost = min(costBoth, cost2);
//                         while(need2 > 0){
//                             ans += 1LL * min_cost;
//                             need2--;
//                         }
//                     }
//                 }
//                 else{
//                     while(need2 > 0){
//                         ans +=  1LL * costBoth;
//                         need1--;
//                         need2--;
//                     }
//                     if(need1 > 0){
//                         min_cost = min(costBoth, cost1);
//                         while(need1 > 0){
//                             ans += 1LL * min_cost;
//                             need1--;
//                         }
//                     }
//                 }
//             }

//             else{
//                 ans += 1LL * need1 * cost1;
//                 ans += 1LL * need2 * cost2;
//                 break;
//             }
            
//         }


//         return ans;


//     }
// };



class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        if(cost1 + cost2 <= costBoth)
            return (1LL * cost1 * need1) + (1LL * cost2 * need2);        

        
        int both = min(need1, need2);
        long long ans = 1LL * both * costBoth;

        need1 -= both;
        need2 -= both;

        if(need1 > 0)
            ans += 1LL * need1 * min(costBoth, cost1);
        else
            ans += 1LL * need2 * min(costBoth, cost2); 

        return ans;

    }
};



