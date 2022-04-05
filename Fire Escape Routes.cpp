// https://www.codechef.com/problems/FIRESC
// Concept used : Depth First Search
#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;

vector < ll > v[100008];
ll visited[100008]={0};

void dfs(ll);
int x=0;

int main(){
    ll t=0,m=0,n=0,a=0,b=0,combinations=1,res=0,i=0;
    cin>>t;
    while(t--){
        cin>>m>>n;
        combinations=1;
        res=0;
        x=0;
        while(n--){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=m;i++){
            if(visited[i]==0){
                res++;
                dfs(i);
                combinations=(combinations*x)%M;
            }
            // cout<<x<<" ";
            x=0;
        }
        cout<<res<<" "<<combinations<<endl;
        memset(v,0,sizeof(v));
        memset(visited,0,sizeof(visited));
    }
    
    //my code
    return 0;
}

void dfs(ll a){
    if(visited[a]==1)
        return;
    x++;
    visited[a]=1;
    for(auto it=v[a].begin();it!=v[a].end();it++){
        dfs(*it);
    }
}
