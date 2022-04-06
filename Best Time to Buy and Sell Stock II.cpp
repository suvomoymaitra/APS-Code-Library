// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Concept used : Dynamic programming
class Solution {
public:
    int cache[30009][3];

    int dp(vector<int>& prices,int i,int n,int x){
        if(i>=n) return 0;
        if(cache[i][x]!=-1) return cache[i][x];
        if(x==0){
            return cache[i][x] = max(dp(prices,i+1,n,1) - prices[i],dp(prices,i+1,n,0));
        }
        else{
            return cache[i][x] = max(dp(prices,i+1,n,0) + prices[i],dp(prices,i+1,n,1));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(cache,-1,sizeof(cache));
        return dp(prices,0,n,0);
    }
};
