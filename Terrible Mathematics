// https://www.codechef.com/ALPAST01/problems/BADMATH
// Concept used : Dynamic programming
#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define nl cout<<"\n";

int powerMod(int x,int y,int m) {
    if (y == 0)return 1;
    int p = powerMod(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

int dp[108][108];

int solve(string s,int m,int n,int i,int curr,int z){
    if(i==n){
        return (curr==0);
    }
    if(dp[i][curr]!=-1) return dp[i][curr];
    int ans=0;
    if(s[i]=='0'){
        ans = solve(s,m,n,i+1,curr,z+1);
    }
    else if(s[i]=='1'){
        int tmp = curr;
        tmp+= powerMod(2,i,m);
        tmp = tmp%m;
        ans = solve(s,m,n,i+1,tmp,z);
    }
    else{
        int tmp = curr;
        tmp+= powerMod(2,i,m);
        tmp = tmp%m;
        ans += solve(s,m,n,i+1,tmp,z);  // for case 1
        ans += solve(s,m,n,i+1,curr,z+1);  // for case 0
    }
    return dp[i][curr] = ans;
}

void suvo(){
    int n=0,m=0;
    cin>>n>>m;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,m,n,0,0,0);
    nl
}

int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        suvo();
    }
    return 0;
}
