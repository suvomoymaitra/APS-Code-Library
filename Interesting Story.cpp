// https://codeforces.com/problemset/problem/1551/C
// Concept used : Greedy and sorting
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
    str s[n];
    rep(i,n) cin>>s[i];
    int ans=0;
    for(char x='a';x<='e';x++){
        vll v;
        rep(i,n){
            int size=s[i].sz;
            int cnt=0;
            rep(j,size) if(s[i][j]==x) cnt++;
            int tmp=size-cnt; // cnt is number of x elements and tmp are the other elements
            v.pb(cnt-tmp);
        }
        sortD(v);
        int res=0;
        int sum=0;
        int size2=v.sz;
        if(v[0]<=0) continue;
        rep(i,size2){
            sum+=v[i];
            if(sum<=0) break;
            if(sum==0 && v[0]==0) break;
            res++;
        }
        ans=max(ans,res);
//        cout<<x<<" "<<res;nl
    }
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
