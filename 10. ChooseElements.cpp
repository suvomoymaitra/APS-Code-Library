// https://atcoder.jp/contests/abc245/tasks/abc245_c
// Concept used : Dynamic programming
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl cout<<"\n";

int n=0,k=0;
vector<pair<int,int>> v;
int dp[200009][3];

int check(int i,int last,int l){
    if(i==0){
        int ans1 = check(i+1,v[i].first,0);
        int ans2 = check(i+1,v[i].second,1);
        return (ans1 or ans2);
    }
    if(i==n){
        if(llabs(last-v[i].first)<=k or llabs(last-v[i].second)<=k) dp[i][l] = 1;
        return dp[i][l];
    }
    if(dp[i][l]!=-1) return dp[i][l];
    int &ans = dp[i][l];
    ans=0;
    if(llabs(last-v[i].first)<=k) ans = ans or check(i+1,v[i].first,0);
    if(llabs(last-v[i].second)<=k) ans = ans or check(i+1,v[i].second,1);
    return ans;
}

void solve() {
    cin>>n>>k;
    for(int i=0;i<n+4;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = -1;
        }
    }

    for(int i=0;i<n;i++){
        int t=0;
        cin>>t;
        pair<int,int> p = {t,0};
        v.push_back(p);
    }
    for(int i=0;i<n;i++) cin>>v[i].second;
    if(check(0,0,0)) cout<<"Yes";
    else cout<<"No";
//    nl
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=2;j++) cout<<dp[i][j]<<" ";
//        nl
//    }

}

int32_t main(){
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
