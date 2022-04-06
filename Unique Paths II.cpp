// https://leetcode.com/problems/unique-paths-ii/
//  Concept used : Dynamic programming
class Solution {
public:
    int dp[102][102];
    int countPaths(vector<vector<int>> obstacleGrid,int i,int j,int n,int m){
        if(i==n-1 and j==m-1) return 1;
        if(i>=n or j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i][j]==1) return 0;
        return dp[i][j] = countPaths(obstacleGrid,i+1,j,n,m) + countPaths(obstacleGrid,i,j+1,n,m);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0;i<102;i++) for(int j=0;j<102;j++) dp[i][j]=-1;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        return countPaths(obstacleGrid,0,0,n,m);
    }
};
