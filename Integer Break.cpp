// https://leetcode.com/problems/integer-break/
// Concept used : Dynamic programming
class Solution {
public:
    int dp[100][100];
    
    
    int fun(int n,int k){
        if(n==0 or k==0) return 1;
        if(dp[n][k]!=-1) return dp[n][k];
        if(k>n) return dp[n][k] = fun(n,k-1);
        return dp[n][k] = max(fun(n,k-1),k*fun(n-k,k));
    }
    
    int integerBreak(int n) {
        for(int i=0;i<100;i++) for(int j=0;j<100;j++) dp[i][j]=-1;
        return fun(n,n-1);
    }
};
