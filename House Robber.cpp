// https://leetcode.com/problems/house-robber/
// concept used : Dynamic programming
class Solution {
public:
    int dp[200][2];
    
    int solve(vector<int>& nums,int n,int i,int x){
        if(i>=n) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        int ans=0;
        if(x==0){
            ans = max(nums[i]+solve(nums,n,i+1,1),solve(nums,n,i+1,0));
        }
        else{
            ans = solve(nums,n,i+1,0);
        }
        return dp[i][x] = ans;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0,0);
    }
};
