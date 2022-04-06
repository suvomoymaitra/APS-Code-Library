// https://codeforces.com/contest/1490/problem/E
// Concept used : Hashing of values and arrays
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
    int n=0;
    cin>>n;
    vll v(n);
    map <int,vector <int> >  m;
    rep(i,n){
        cin>>v[i];
        m[v[i]].pb(i+1);
    }
    vector <pair<int,pair<int,int>> > v1;
    auto itr = m.begin();
    v1.pb(mp(itr->fi,mp(itr->se.sz,itr->fi*itr->se.sz)));
    auto itr1 = m.begin();
    itr1++;
    int i=0;
    while(itr1!=m.end()){
        v1.pb(mp(itr1->fi,mp(itr1->se.sz,v1[i].se.se+(itr1->se.sz*itr1->fi))));
        i++;
        itr1++;
    }
    int x=v1.sz;
//    rep(i,x) cout<<v1[i].fi<<" "<<v1[i].se.fi<<" "<<v1[i].se.se;nl
    set <int> ans;
    rep(k,m[v1[x-1].fi].sz) ans.insert(m[v1[x-1].fi][k]);
    repD(i,x-2,0){
        if(v1[i].se.se>=v1[i+1].fi){
            rep(k,m[v1[i].fi].sz) ans.insert(m[v1[i].fi][k]);
        }
        else break;
    }
    cout<<ans.sz;nl
    print(ans);nl
//    set <int> res;
//    int y=ans.sz;
//    rep(i,y){
//        rep(j,n) if(v[j]==ans[i]) res.insert(j+1);
//    }
//    cout<<res.sz;nl
//    print(res);nl
}

int32_t main(){
    fast
    int t=1;
    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
