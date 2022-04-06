// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Concept used : Dynamic programming
class Solution {
public:
    int dp[6000][3][3];    
    
    int solve(vector<int> & nums,int n,int i,int x,int cd){
        if(i>=n) return 0;
        if(dp[i][x][cd]!=-1) return dp[i][x][cd];
        int ans;
        if(x==0){
            if(cd==0) ans = max(solve(nums,n,i+1,1,1) - nums[i],solve(nums,n,i+1,0,0));
            else ans = solve(nums,n,i+1,0,0);
        }
        if(x==1) ans = max(solve(nums,n,i+1,0,1) + nums[i],solve(nums,n,i+1,1,0));
        return dp[i][x][cd] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0,0,0);
    }
};
