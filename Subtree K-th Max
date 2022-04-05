// https://atcoder.jp/contests/abc239/tasks/abc239_e
// Concept used : Dynamic programming on tree
#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> edges[100009],dp[100009],visited(100009),value(100009);

void dfs(int x,int y){
    visited[x]=1;
    for(auto itr:edges[x]){
        // explore all nodes connected to it except its parent
        if(itr!=y){
            dfs(itr,x);
            //after exploring its child append all the values of its child to get the values from its subtree
            for(auto itr1:dp[itr]) dp[x].push_back(itr1);
        }
    }
    dp[x].push_back(value[x]);
    sort(dp[x].begin(),dp[x].end());
    reverse(dp[x].begin(),dp[x].end());
    while(dp[x].size()>20) dp[x].pop_back();
}

int32_t main(){
    int n=0,q=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        visited[i] = 0;
        cin>>value[i];
    }
    for(int i=0;i<n-1;i++){
        int a=0,b=0;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,10000000);
    while(q--){
        int v=0,k=0;
        cin>>v>>k;
        cout<<dp[v][k-1]<<"\n";
    }


    return 0;
}
