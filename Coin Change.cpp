// https://leetcode.com/problems/coin-change/
// Concept used : Dynamic programming
class Solution {
public:
    int dp[15][10009];
    
    int solve(vector<int> &coins,int n,int amount){
        if(amount==0 || n==0){
            if(amount==0) return 0;
            else return INT_MAX-4;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        if(amount>=coins[n-1]){
            return dp[n][amount] = min(solve(coins,n-1,amount),solve(coins,n,amount-coins[n-1])+1);
        }
        else
            return dp[n][amount] = solve(coins,n-1,amount);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,n,amount);
        if(ans==INT_MAX-4) return -1;
        else return ans;
    }
};
