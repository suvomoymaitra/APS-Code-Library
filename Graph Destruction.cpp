// https://atcoder.jp/contests/abc229/tasks/abc229_e
// Concept used : Disjoint set union
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

#define SIZE 200009

int arr[SIZE];
int dsusize[SIZE];

int dsuroot(int a){
    while(arr[a]!=a){
        arr[a]=arr[arr[a]];
        a=arr[a];
    }
    return a;
}

bool dsufind(int a,int b){
    if(dsuroot(a)==dsuroot(b))
        return true;
    return false;
}


void dsuinitialize(){
    int i=0;
    for(i=0;i<SIZE;i++){
        arr[i]=i;
        dsusize[i]=1;
    }
}

void dsuunion(int a,int b){
    int root_a=dsuroot(a);
    int root_b=dsuroot(b);
    if(dsusize[root_a]>dsusize[root_b]){
        arr[root_b]=arr[root_a];
        dsusize[root_a]+=dsusize[root_b];
    }
    else{
        arr[root_a]=arr[root_b];
        dsusize[root_b]+=dsusize[root_a];
    }
}

void pre(){}

void solve() {
    dsuinitialize();
    int n=0,m=0;
    cin>>n>>m;
    vll ans;
    ans.pb(0);
    vector <int> edges[n+1];
    rep(i,m){
        int a=0,b=0;
        cin>>a>>b;
        edges[a].pb(b);
    }
    int j=0;
    int res=0;
    repD(i,n,2){
        res++;
        for(auto itr:edges[i]){
            if(!dsufind(i,itr)){
                dsuunion(i,itr);
                res--;
            }
        }
        ans.pb(res);
    }
    reverse(ALL(ans));
    rep(i,n) cout<<ans[i]<<"\n";
}

//1
//6
//5 5 5 5 2 2

int32_t main(){
    fast
    int t=1;
//    cin>>t;
    pre();
    rep(i,t){
//        cout<<"case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
