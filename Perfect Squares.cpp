// https://leetcode.com/problems/perfect-squares/
// Concept used : Dynamic programming
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++) dp[i] = 9999;
        int x = 1;
        dp[0]=0;
        while(x*x<=n){
            for(int i=x*x;i<=n;i++){
                dp[i] = min(dp[i],dp[i-(x*x)]+1);
            }
            x++;
        }
        return dp[n];
    }
};
