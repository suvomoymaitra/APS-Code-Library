// https://www.codechef.com/problems/DISHOWN
// Concept used : Disjoint Set Union
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

#define SIZE 10009

int arr[SIZE];
int dsusize[SIZE];

void dsuinitialize(int n){
    for(int i=1;i<=n;i++){
        dsusize[i] = 1;
        arr[i] = i;
    }
}

int dsuroot(int a){
    while(arr[a]!=a){
        arr[a] = arr[arr[a]];
        a = arr[a];
    }
    return a;
}

bool dsufind(int a,int b){
    return (dsuroot(a)==dsuroot(b));
}

void dsuunion(int a,int b){
    int roota = dsuroot(a);
    int rootb = dsuroot(b);
//    if(!dsufind(a,b)){
//        if(dsusize[roota]>dsusize[rootb]){
//            dsusize[roota]+=dsusize[rootb];
            arr[rootb] = roota;
//        }
//        else{
//            dsusize[rootb]+=dsusize[roota];
//            arr[roota] = rootb;
//        }
//    }
}

void pre(){

}

void solve() {
    int n=0;
    cin>>n;
    dsuinitialize(n+2);
    vll v(n+1);
    repA(i,1,n) cin>>v[i];
    int q=0;
    cin>>q;
    rep(i,q){
        int t=0;
        cin>>t;
        if(t==0){
            int a=0,b=0;
            cin>>a>>b;
            if(dsufind(a,b)){
                cout<<"Invalid query!";nl
            }
            else{
                int roota = dsuroot(a);
                int rootb = dsuroot(b);
                if(v[roota]>v[rootb]){
                    dsuunion(a,b);
                }
                elif(v[roota]<v[rootb]){
                    dsuunion(b,a);
                }
            }
        }
        else{
            int a=0;
            cin>>a;
            cout<<dsuroot(a);nl
        }
    }
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
