// https://codeforces.com/problemset/problem/1622/C
// Concept used : Sorting and prefix sum
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

void pre(){}

void solve() {


    int n=0,k=0;
    cin>>n>>k;
    vll v(n+1,0);
    repA(i,1,n) cin>>v[i];
    sortA(v);
    vll presum(n+1,0);
    repA(i,1,n) presum[i] = presum[i-1]+v[i];
    int ans=presum[n]-k;
//    print(v);nl
    if(presum[n]<=k){
        cout<<0;
        nl
        return;
    }
    repA(i,1,n){
        int zz=0;
        int x = k-presum[i]+v[1];
        if(x>=0){
            int tmp = x/(n-i+1);
            if(tmp>v[1]){
                zz+=(n-i);
            }
            else{
                zz+=(n-i);
                zz+=(v[1]-tmp);
            }
        }
        else{
            int tmp = x/(n-i+1);
            if(x%(n-i+1)){
                tmp--;
            }
            zz+=n-i;
            zz+=(v[1]-tmp);
        }
        ans=min(ans,zz);
    }
    cout<<ans;nl


//    int n=0,k=0;
//    cin>>n>>k;
//    vll v(n+1,0);
//    repA(i,1,n) cin>>v[i];
//    sortA(v);
//    vll presum(n+1,0);
//    repA(i,1,n) presum[i] = presum[i-1]+v[i];
//    int ans=presum[n]-k;
////    print(v);nl
//    if(presum[n]<=k){
//        cout<<0;
//        nl
//        return;
//    }
//    repA(i,1,n){
//        int zz=0;
//        int x = k - presum[i-1];
//        int tmp = x/(n-i+1);
////        cout<<x<<" "<<tmp;nl
//        if(x%(n-i+1)){
//            tmp++;
//            zz+=n-i;
//            zz+=v[i]-tmp;
//            zz+=(x%(n-i+1));
//        }
//        else{
//            zz+=n-i;
//            zz+=v[i]-tmp;
//        }
//        ans = min(ans,zz);
//    }
//    cout<<ans;nl
}

int32_t main(){
    fast
    int t=1;
    cin>>t;
    pre();
    rep(i,t){
        solve();
    }
    return 0;
}
