// https://leetcode.com/problems/unique-paths/
// Concept used : Dynamic programming
class Solution {
public:
    int dp[102][102];
    int countpaths(int n,int m){
        if(n==1 or m==1) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m]=countpaths(n-1,m)+countpaths(n,m-1);
    }
    
    int uniquePaths(int m, int n) {
        for(int i=0;i<102;i++) for(int j=0;j<102;j++) dp[i][j]=-1;
        return countpaths(n,m);
    }
};
