// https://atcoder.jp/contests/dp/tasks/dp_d
// Concept used : Dynamic programming
//  299143BT
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pi 3.1415926535
#define fi first
#define se second
#define vll vector<ll>
#define vpll vector<pair <ll,ll> >
#define vvll vector< vll >
#define str string
#define umap unordered_map
#define uset unordered_set
#define rep(i,n) for(ll i=0;i<n;i++)
#define repA(i,s,n) for(ll i=s;i<=n;i++)
#define repD(i,s,n) for(ll i=s;i>=n;i--)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define elif else if
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define sortA(v) sort(ALL(v))
#define sortD(v) sort(ALL(v),greater <ll> ())
#define print(v) for(auto itr:v) cout<<itr<<" ";
#define sz size()
#define nl cout<<"\n";
using namespace std;
ll factorial(ll n){return (n==1||n==0)?1:n*factorial(n-1);}
ll power(ll x,ll y){ll res=1;while(y>0){if(y&1)res=res*x;y=y>>1;x=x*x;}return res;}
ll powerMod(ll x,ll y,ll m){if(y==0)return 1;ll p=powerMod(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll modInverse(ll a,ll m){return powerMod(a,m-2,m);}
ll gcd(ll a,ll b){if(a==0){return b;}else if(b==0){return a;}else{if(a>b){return gcd(a%b,b);}else{return gcd(b%a,a);}}}

vll wt,val;
ll n=0,w;

void pre(){}

void solve(ll t) {
//    cout<<"case #"<<t+1<<": ";
    cin>>n>>w;
    rep(i,n){
        ll x=0,y=0;
        cin>>x>>y;
        wt.pb(x);
        val.pb(y);
    }
    ll dp[n+1][w+1];
    memset(dp,0,sizeof(dp));
    repA(i,1,n){
        repA(j,1,w){
            if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][w];
}

int main(){
    fast
    ll t=1;
//    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
