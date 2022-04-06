// https://atcoder.jp/contests/dp/tasks/dp_c
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

ll dp[3];
vll a,b,c;
ll n=0;

void pre(){}

void solve(ll t) {
//    cout<<"case #"<<t+1<<": ";
    cin>>n;
    rep(i,n){
        ll x=0,y=0,z=0;
        cin>>x>>y>>z;
        a.pb(x);
        b.pb(y);
        c.pb(z);
    }
    dp[0]=a[0];
    dp[1]=b[0];
    dp[2]=c[0];
    repA(i,1,n-1){

        ll x=a[i]+max(dp[1],dp[2]);
        ll y=b[i]+max(dp[0],dp[2]);
        ll z=c[i]+max(dp[0],dp[1]);
        dp[0]=x;
        dp[1]=y;
        dp[2]=z;
//        cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2];nl
    }
    cout<<max(dp[0],max(dp[1],dp[2]));
}

int main(){
    fast
    ll t=1;
//    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
