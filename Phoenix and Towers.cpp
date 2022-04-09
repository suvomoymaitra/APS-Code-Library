// https://codeforces.com/problemset/problem/1515/C
// Concept used : Set
//  299143BT
#include<bits/stdc++.h>
#define ll int64_t
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

ll nc2(ll n){
    if(n==1) return 0;
    else return (n*(n-1)/2);
}

void pre(){}

void solve(ll t){
//    cout<<"case #"<<t+1<<": ";


    ll n=0,m=0,x=0;
    cin>>n>>m>>x;
    vll v(n);
    rep(i,n) cin>>v[i];
    cout<<"yes";nl
    set <pair<ll,ll>> s;
    rep(i,m) s.insert(mp((ll)0,i+1));
    rep(i,n){
        auto tmp=s.begin();
        s.erase(tmp);
        cout<<tmp->se<<" ";
        s.insert(mp(tmp->fi+v[i],tmp->se));
    }
    nl
}

int main(){
    fast
    ll t=1;
    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
