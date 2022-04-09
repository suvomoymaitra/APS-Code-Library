// https://codeforces.com/problemset/problem/1399/D
// Concept used : Constructive algorithm
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
    vll ans(n);
    str s;
    cin>>s;
    vll zeroes,ones;
    int mx = 0;
    rep(i,n){
        int x = zeroes.sz+ones.sz;
        if(s[i]=='1'){
            if(ones.sz==0){
                zeroes.pb(x);
            }
            else{
                x=ones.back();
                ones.pop_back();
                zeroes.pb(x);
            }
        }
        else{
            if(zeroes.sz==0){
                ones.pb(x);
            }
            else{
                x=zeroes.back();
                zeroes.pop_back();
                ones.pb(x);
            }
        }
        ans[i]=x;
        mx=max(mx,ans[i]+1);
    }
    cout<<mx;nl
    rep(i,n) cout<<ans[i]+1<<" ";
    nl
}

int32_t main(){
    fast
    int t=1;
    cin>>t;
    pre();
    rep(i,t) solve(t);
    return 0;
}
