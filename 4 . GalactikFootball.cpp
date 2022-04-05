// https://www.codechef.com/problems/GALACTIK
// Concept used : Depth First Search
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

vector<int> v[100009];
vector<int> visited(100009,0);
vector<int> cost(100009);

int curr;

void add_edge(int a,int b){
    v[a].pb(b);
    v[b].pb(a);
}

void dfs(int a){
//    if(visited[a]==1) return;
    visited[a] = 1;
//    cout<<a;nl
    if(cost[a]>=0) curr = min(curr,cost[a]);
    for(auto itr:v[a]){
        if(!visited[itr]) dfs(itr);
    }
}

void pre(){

}

void solve() {
    int n=0,m=0;
    cin>>n>>m;
    rep(i,m){
        int a=0,b=0;
        cin>>a>>b;
        add_edge(a,b);
    }
    rep(i,n){
        int t=0;
        cin>>t;
        cost[i+1] = t;
    }
    int ans=0;
    int tmp=0;
    int mn = LLONG_MAX;
    int flag=0;
    repA(i,1,n){
        if(visited[i]==0){
            tmp++;
            curr = LLONG_MAX;
            dfs(i);
            if(curr==LLONG_MAX){
                flag=1;
            }
            ans+=curr;
            mn = min(mn,curr);
//            cout<<i<<":"<<curr<<":"<<ans;nl
//            repA(j,1,n) cout<<visited[j]<<" ";
//            nl
        }
    }
    if(tmp==1) cout<<0;
    elif(flag) cout<<-1;
    else cout<<(mn*(tmp-1))+ans-mn;
    nl
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
