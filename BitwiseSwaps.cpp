// https://www.codechef.com/FEB222B/problems/BITSWAPS
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



#define SIZE 300009

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


void dsuinitialize(int x){
    int i=0;
    for(i=0;i<=x;i++){
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


void pre(){

}


void solve() {
    int n=0;
    cin>>n;
    vll v(n);
    map<int,vll> m;
    map<int,int> m1;
    dsuinitialize(n+2);
    rep(i,n){
        cin>>v[i];
        int t = v[i];
        m1[v[i]] = i;
        if(t==0) continue;
        while(t%2==0) t/=2;
        if(t==1){
            m[v[i]].pb(i);
        }
    }
    for(auto itr:m){
        rep(i,itr.se.sz-1){
            dsuunion(itr.se[i],itr.se[i+1]);
        }
    }
    vll v1 = v;
    sortA(v1);
    rep(i,n){
        rep(j,32){
            if((1<<j)&v[i] and m[1<<j].sz){
                dsuunion(m[1<<j].back(),i);
            }
            elif((1<<j)&v[i]){
                m[1<<j].pb(i);
            }
        }
    }
//    rep(i,n+1) cout<<arr[i]<<" ";nl
//    for(auto itr:m1){
//        cout<<itr.fi<<" "<<itr.se;nl
//    }
    rep(i,n){
        if(v[i]!=v1[i] and (!dsufind(i,m1[v1[i]]))){
//            cout<<v[i]<<":"<<v1[i];nl
            cout<<"No";nl
            return;
        }
    }
    cout<<"Yes";nl

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
