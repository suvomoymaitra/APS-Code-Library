// https://www.codechef.com/START30B/problems/MINCOLOR
#include<bits/stdc++.h>
using namespace std;
#define int long long int

//vector<int> v[10];
int n=0,m=0;

void dfs2(int a,int b,int last,vector<vector<int>> &v){
    if(a<0 or b<0 or a>=n or b>=m) return;
    if(v[a][b]!=0) return;
    int curr=0;
    if(last==2) curr=1;
    else curr = 2;
    v[a][b] = curr;
    dfs2(a-1,b,curr,v);
    dfs2(a,b-1,curr,v);
    dfs2(a,b+1,curr,v);
    dfs2(a+1,b,curr,v);

}

void dfs3(int a,int b,int last,vector<vector<int>> &v){
    if(a<0 or b<0 or a>=n or b>=m) return;
    if(v[a][b]!=0 and last!=4 and v[a][b]!=3) return;
    if(last==4) v[a][b] = 1;
    int curr=0;
    if(last==3) curr=1;
    else if(last==4) curr=3;
    else if(last==1) curr=2;
    else curr=1;
    if(v[a][b]==0) v[a][b] = curr;
    dfs3(a-1,b,curr,v);
    dfs3(a,b-1,curr,v);
    dfs3(a,b+1,curr,v);
    dfs3(a+1,b,curr,v);
}

void suvo(){
//    int n=0,m=0;
    cin>>n>>m;
    vector<vector<int>> v(n);
//    v->resize(n);
    vector<int> tmp(m);
    for(int i=0;i<n;i++) v[i] = tmp;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) v[i][j] = 0;
    int a=0,b=0;
    cin>>a>>b;
    v[a-1][b-1] = 1;
    int c=0,d=0;
    cin>>c>>d;
    v[c-1][d-1] = 2;
    int sum = llabs(a-c)+llabs(b-d);
    sum%=2;
    if(sum%2){
        v[a-1][b-1] = 0;
        dfs2(a-1,b-1,2,v);
    }
    else{
        if(a-1>=0 and b-2>=0) v[a-1][b-2] = 3;
        if(a-2>=0 and b-1>=0) v[a-2][b-1] = 3;
        if(a-1>=0 and b<m) v[a-1][b] = 3;
        if(a<n and b-1>=0) v[a][b-1] = 3;
        dfs3(a-1,b-1,4,v);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=0;
    cin>>test;
    while(test--) suvo();
    return 0;
}
