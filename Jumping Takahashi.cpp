// https://atcoder.jp/contests/abc240/tasks/abc240_c
// Concept used : Dynamic programming
//  299143BT
#include<bits/stdc++.h>
#define int long long int
#define MOD 1000000007
#define pi 3.1415926535
#define fi first
#define se second
#define vll vector<int>
#define vpll vector<pair <int,int> >
#define vvll vector< vll >
#define str string
#define umap unordered_map
#define uset unordered_set
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(i,s,n) for(int i=s;i<=n;i++)
#define repD(i,s,n) for(int i=s;i>=n;i--)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define elif else if
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define sortA(v) sort(ALL(v))
#define sortD(v) sort(ALL(v),greater <int> ())
#define print(v) for(auto itr:v) cout<<itr<<" ";
#define sz size()
#define nl cout<<"\n";
using namespace std;
int factorial(int n){return (n==1||n==0)?1:n*factorial(n-1);}
int power(int x,int y){int res=1;while(y>0){if(y&1)res=res*x;y=y>>1;x=x*x;}return res;}
int powerMod(int x,int y,int m){if(y==0)return 1;int p=powerMod(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
int modInverse(int a,int m){return powerMod(a,m-2,m);}
int gcd(int a,int b){if(a==0){return b;}else if(b==0){return a;}else{if(a>b){return gcd(a%b,b);}else{return gcd(b%a,a);}}}
int ceil_div(int a,int b){return (a/b)+((a%b)>0);}

int cache[200][4][10080];

void pre(){
    rep(i,150) rep(j,3) rep(k,10006) cache[i][j][k] = -1;
}

bool solve(vpll v,int n,int x,int i,int curr,int last){
//    if(i==n) cout<<curr<<"\n";
    if(i==n and curr==x) return true;
    if(curr>=x) return false;
    if(i==n) return false;
//    if(cache[i][last][curr]!=-1) return cache[i][last][curr];
//
//    cache[i][0][curr] = solve(v,n,x,i+1,curr+v[i].fi,0);
//    cache[i][1] = solve(v,n,x,i+1,curr+v[i].se,1);
//
//    return cache[i][0] || cache[i][1];

    if(cache[i][last][curr]!=-1) return cache[i][last][curr];
    return cache[i][last][curr] = (solve(v,n,x,i+1,curr+v[i].fi,0) || solve(v,n,x,i+1,curr+v[i].se,1));
}

void solve() {
    int n=0,x=0;
    cin>>n>>x;
    vpll v;
    rep(i,n){
        int a=0,b=0;
        cin>>a>>b;
        v.pb({a,b});
    }
    if(solve(v,n,x,0,0,0)==0) cout<<"No";
    else cout<<"Yes";
//    nl
//    rep(i,n){
//        rep(j,2){
//            cout<<cache[i][j]<<" ";
//        }
//        nl
//    }


}

int32_t main(){
    fast
    int t=1;
//    cin>>t;
    pre();
    rep(i,t){
        solve();
    }
    return 0;
}
