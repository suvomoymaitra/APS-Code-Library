// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
// Concept used : Depth first search
class Solution {
public:
    
    vector<int> v[1009];
    vector<int> visited;
    
    void dfs(int a,int i,vector<vector<int>> &ans){
        visited[a] = 1;
        if(i!=a) ans[i].push_back(a);
        for(auto itr:v[a]){
            if(!visited[itr]){
                dfs(itr,i,ans);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // for(int i=0;i<edges.size();i++){
        //     for(auto &itr:edges[i]){
        //         ans[itr].push_back(i);
        //     }
        // }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++) visited.push_back(0);
        for(int i=0;i<edges.size();i++){
            // cout<<edges[i][0]<<" "<<edges[i][1]<<"\n";
            int a = edges[i][0];
            int b = edges[i][1];
            // ans[b].push_back(a);
            v[b].push_back(a);
        }
        
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++) visited[i] = 0;
            dfs(i,i,ans);
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
