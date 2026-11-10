class Solution {
public:
    vector<int> t;

    int solve(int i, int N, vector<int>& costs){
        if(i == N)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        int cost = INT_MAX;
        int j = i+1;
        if(j <= N)
            cost = solve(j, N, costs) + costs[j - 1] + (j - i) * (j - i);
        
        j = i + 2;
        if(j <= N)
            cost = min(cost, solve(j, N, costs) + costs[j - 1] + (j - i) * (j - i));

        j = i+3;
        if(j <= N)
            cost = min(cost, solve(j, N, costs) + costs[j - 1] + (j - i) * (j - i));

        return t[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        t.assign(n+1, -1);

        return solve(0, n, costs);
        
    }
};