// https://codeforces.com/contest/1631/problem/C
// Concept used : Bit manipulation
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

void pre() {

}



void solve() {
    int n=0,k=0;
    cin>>n>>k;
    if(k>=n){
        cout<<-1;nl
        return;
    }
    set<int> s;
    rep(i,n) s.insert(i);
    if(k==0){
        while(s.sz){
            auto itr = *s.begin();
            cout<<itr<<" "<<((n-1)^itr);nl
            s.erase(itr);
            s.erase((n-1)^itr);
        }
    }
    elif(k<n-1){
        cout<<n-1<<" "<<k;nl
        cout<<0<<" "<<((n-1)^k);nl
        s.erase(n-1);
        s.erase(0);
        s.erase(k);
        s.erase((n-1)^k);
        while(s.sz){
            auto itr = *s.begin();
            cout<<itr<<" "<<((n-1)^itr);nl
            s.erase(itr);
            s.erase((n-1)^itr);
        }
    }
    else{
        if(n==4){
            cout<<-1;nl
            return;
        }
        cout<<"1 3";nl
        cout<<2<<" "<<n-3;nl
        cout<<0<<" "<<n-4;nl
        cout<<n-1<<" "<<n-2;nl
        s.erase(0);
        s.erase(1);
        s.erase(2);
        s.erase(3);
        s.erase(n-1);
        s.erase(n-2);
        s.erase(n-3);
        s.erase(n-4);
        while(s.sz){
            auto itr = *s.begin();
            cout<<itr<<" "<<((n-1)^itr);nl
            s.erase(itr);
            s.erase((n-1)^itr);
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
