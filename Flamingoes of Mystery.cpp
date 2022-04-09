// https://codeforces.com/contest/1425/problem/F
// Concept used : Interactive
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
#define print(v) for(auto itr:v) cout<<*itr<<" ";
#define sz size()
#define nl cout<<"\n";
using namespace std;
ll factorial(ll n){return (n==1||n==0)?1:n*factorial(n-1);}
ll power(ll x,ll y){ll res=1;while(y>0){if(y&1)res=res*x;y=y>>1;x=x*x;}return res;}
ll powerMod(ll x,ll y,ll m){if(y==0)return 1;ll p=powerMod(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll modInverse(ll a,ll m){return powerMod(a,m-2,m);}
ll gcd(ll a,ll b){if(a==0){return b;}else if(b==0){return a;}else{if(a>b){return gcd(a%b,b);}else{return gcd(b%a,a);}}}

void pre(){

}

void solve(){
    ll n=0,l=0,r=0,x=0;
    cin>>n;
    fflush(stdout);
    vll v(n),v1(n-1);
    rep(i,n-1){
        cout<<"? 1 "<<i+2;nl
        fflush(stdout);
        cin>>x;
        v1[i]=x;
    }
    cout<<"? 2 3\n";
    fflush(stdout);
    cin>>x;
    repD(i,n-1,2){
        v[i]=v1[i-1]-v1[i-2];
    }
    v[0]=v1[1]-x;
    v[1]=v1[0]-v[0];
    cout<<"! ";
    rep(i,n) cout<<v[i]<<" ";
    fflush(stdout);

}
int main(){

    ll t=1;
//    cin>>t;
    pre();
    while(t--) solve();
    return 0;
}
