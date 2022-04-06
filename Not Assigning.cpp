// https://codeforces.com/contest/1627/problem/C
// Concept used : Depth first search
#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector <int> edges[100008];
vector <int> visited(100008);
vector <int> ans(100008);
map <pair<int,int>,int> m;
int temp=1;
void dfs(int x,int last){
    if(visited[x]) return;
    visited[x] = 1;
    int z=0;
    if(edges[x].size()>2) temp=0;
    for(auto itr:edges[x]){
        if(!visited[itr]){
            ans[m[{x,itr}]] = last;
            if(last==2) last=3;
            else last=2;
            dfs(itr,last);
            z++;
        }
    }
}

int32_t main(){
    int test=0;
    cin>>test;
    while(test--){
        temp=1;
        int n=0;
        cin>>n;
        for(int i=0;i<n+4;i++){
            visited[i] = 0;
            edges[i].clear();
        }
        int tmp=0;
        for(int i=0;i<n-1;i++){
            int a=0,b=0;
            cin>>a>>b;
            tmp=a;
            edges[a].push_back(b);
            edges[b].push_back(a);
            m[{a,b}] = i;
            m[{b,a}] = i;
        }
        dfs(1,3);
        int x=1;
        if(!temp) cout<<-1;
        else for(int i=0;i<n-1;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
