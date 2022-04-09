// https://codeforces.com/contest/1626/problem/C
// Concept used : Greedy
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
    vll k(n+2);
    vll h(n+2);
    k[0] = 0;
    h[0] = 0;
    repA(i,1,n) cin>>k[i];
    repA(i,1,n) cin>>h[i];
    int ans = 0;
    int i = n;
    while(i>=1){
         int j = i-1;
         int diff = k[i] - k[j];
         if(h[i]<=diff){
             ans+=((h[i]+1)*h[i]/2);
//             cout<<"here";
             i--;
         }
         else{
             int df = diff;
             int tmp = h[i];
             while(j>0 and tmp>df){
                 tmp = max(tmp,h[j]+(k[i]-k[j]));
                 j--;
                 df = k[i] - k[j];
             }
             i=j;
             ans+=((tmp+1)*tmp/2);
         }
    }
    cout<<ans;nl


//    int n=0;
//    cin>>n;
//    vll k(n);
//    vll h(n);
//    rep(i,n) cin>>k[i];
//    rep(i,n) cin>>h[i];
//    int prev = -1;
//    int ans=0;
////    print(k);nl
////    print(h);nl
//    int z=0;
//    while(z<n){
////        cout<<"here1";
//        if(z+1<n and k[z]+1==k[z+1] and h[z]==h[z+1] and h[z]!=1){
//            int x=h[z];
//            int tmp=1;
////            cout<<x;nl
////            cout<<"here2";
//            while(z+1<n and k[z]+1==k[z+1] and h[z+1]==x){
//                h[z+1]+=tmp;
//                tmp++;
//                z++;
////                cout<<"here3";
//            }
//        }
//        else z++;
//    }
////    print(h);nl
//    repD(i,n-1,0){
//        if(i==0){
//            int x = max(prev,h[i]);
//            int t = k[i];
//            ans+=(x*(x+1)/2);
////            cout<<prev<<" "<<h[i];nl
//        }
//        else{
//            int x = max(prev,h[i]);
//            int t = k[i]-k[i-1];
//
//            if(t>=x){
//                ans+=(x*(x+1)/2);
//                prev = -1;
//            }
//            else{
//                prev = h[i]-t;
//                ans+=(x*(x+1)/2)-(prev*(prev+1)/2);
//            }
//        }
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
