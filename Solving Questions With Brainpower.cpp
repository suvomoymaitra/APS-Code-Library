// https://leetcode.com/problems/solving-questions-with-brainpower/
// Concept used : Dynamic programming
class Solution {
public:
    long long dp[100008];
    long long solve(vector<vector<int>> &q,long long n,long long i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(q[i][0]+solve(q,n,i+1+q[i][1]),solve(q,n,i+1));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        long long ans = solve(questions,questions.size(),0);
        return ans;
        
    }
};
