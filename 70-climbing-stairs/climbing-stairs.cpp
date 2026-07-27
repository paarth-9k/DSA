class Solution {
public:
    int func_dp(int i, vector<int>& dp)
    {
        if(i == 0 || i == 1)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = func_dp(i - 1, dp)  + func_dp(i - 2, dp);
    }


    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func_dp(n, dp);
    }
};
