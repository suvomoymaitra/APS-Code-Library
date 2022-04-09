// https://codeforces.com/problemset/problem/1546/C
// Concept used : Hashing and sorting
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
    int n=0;
    cin>>n;
    vll v(n);
    vll v1(n);
    rep(i,n){
        cin>>v[i];
        v1[i]=v[i];
    }
    map<int,vll> m;
    sortA(v1);
    if(v==v1){
        cout<<"YES";nl
        return;
    }
    set<int> s;
    rep(i,n) s.insert(v[i]);
    for(auto &itr:s){
        m[itr].pb(0);
        m[itr].pb(0);
    }
    rep(i,n){
        m[v1[i]][i%2]++;
    }
    rep(i,n){
        if(m[v[i]][i%2]>0){
            m[v[i]][i%2]--;
        }
        else{
            cout<<"no";nl
            return;
        }
    }
    cout<<"yes";nl
//    vll tmp(n);
//    rep(i,n){
//        int flag=0,pos=-1;
//        rep(j,m[v[i]].sz){
//            if(llabs(m[v[i]][j]-i)%2==0){
//                pos=j;
//                flag=1;
//                break;
//            }
//        }
//        if(flag==0){
//            cout<<"NO";
//            nl
//            return;
//        }
//        else{
//            tmp[i]=pos;
//            m[v[i]].erase(m[v[i]].begin()+pos);
//        }
//        tmp[i]=llabs(m[v[i]].back()-i);
//    }
//    print(tmp);nl
//    rep(i,n) if(tmp[i]%2==1){
//        cout<<"NO";nl
//        return;
//    }
//    cout<<"YES";
//    nl
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
