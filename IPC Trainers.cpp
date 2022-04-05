// https://www.codechef.com/problems/IPCTRAIN
// Concept used : Heap or priority queue
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

void pre(){

}


void solve() {
    int n=0,d=0;
    cin>>n>>d;
    multiset<pair<int,pair<int,int>>> ms;
    rep(i,n){
        int a=0,b=0,c=0;
        cin>>a>>b>>c;
        ms.insert({a,{b,c}});
    }
    multiset<pair<int,pair<int,int>>> ms1;
    int curr=0;
    int ans=0;
    while(curr<=d){
        while(1) {
            auto itr = ms.begin();
            int dd = itr->fi;
            int tt = itr->se.fi;
            int ss = itr->se.se;
            if(dd==curr){
                ms.erase(itr);
                ms1.insert({ss,{tt,dd}});
            }
            else break;
        }
        if(ms1.sz){
            auto itr = ms1.end();
            itr--;
            int ss = itr->fi;
            int tt = itr->se.fi;
            int dd = itr->se.se;
            ms1.erase(itr);
            if(tt>1){
                ms1.insert({ss,{tt-1,dd}});
            }
        }
        curr++;
    }
    for(auto itr:ms1){
        ans+=(itr.fi*itr.se.fi);
    }
    cout<<ans;nl
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
