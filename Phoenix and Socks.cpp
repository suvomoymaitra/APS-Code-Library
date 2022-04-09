// https://codeforces.com/problemset/problem/1515/D
// Concept used : Sorting and hashing
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

void pre(){}

void solve(int t) {
    int n=0,l=0,r=0;
    cin>>n>>l>>r;
    map <int,pair <int,int>> m;
    vll v(n);
    int ans=0;
    rep(i,n){
        cin>>v[i];
        if(i<l) m[v[i]].fi++;
        else m[v[i]].se++;
    }
    for(auto &itr : m){
        int mn = min(itr.se.fi,itr.se.se);
        itr.se.fi-=mn;
        itr.se.se-=mn;
        l-=mn;
        r-=mn;
    }
    int mn = min(l,r);
    ans+=mn;
    l-=mn;
    r-=mn;
    if(l>r){
        for(auto &itr : m){
            if(mn<=0) break;
            if(itr.se.fi%2) itr.se.fi--,mn--;
        }
        for(auto &itr : m){
            if(mn<=0) break;
            int mn1 = min(itr.se.fi,mn);
            mn-=mn1;
            itr.se.fi-=mn1;
        }
        for(auto itr : m){
            if(itr.se.fi%2) ans++;
            ans+=itr.se.fi/2;
        }
    }
    elif(r>l){
        for(auto &itr : m){
            if(mn<=0) break;
            if(itr.se.se%2) itr.se.se--,mn--;
        }
        for(auto &itr : m){
            if(mn<=0) break;
            int mn1 = min(itr.se.se,mn);
            mn-=mn1;
            itr.se.se-=mn1;
        }
        for(auto itr : m){
            if(itr.se.se%2) ans++;
            ans+=itr.se.se/2;
        }
    }
    else ans+=l;
    cout<<ans;nl
}

int32_t main(){
    fast
    int t=1;
    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
