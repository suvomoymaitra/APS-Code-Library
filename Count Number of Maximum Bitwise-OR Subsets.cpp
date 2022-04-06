// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Concept used : Basic recursion
class Solution {
public:
    int ans;
    int mx;
    
    void calc(vector<int>& nums,int i,int curr){
        if(i>=nums.size()) return;
        calc(nums,i+1,curr | nums[i]);
        calc(nums,i+1,curr);
        mx = max(mx,curr);
        mx = max(mx,curr | nums[i]);
    }
    
    void solve(vector<int> & nums,int n,int i,int curr){
        if(i>=n) return;
        solve(nums,n,i+1,curr|nums[i]);
        if((curr|nums[i])==mx) ans++;
        solve(nums,n,i+1,curr);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        ans = 0;
        mx = 0;
        calc(nums,0,0);
        int n = nums.size();
        solve(nums,n,0,0);
        // cout<<mx;
        return ans;
    }
};
