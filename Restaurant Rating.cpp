// https://www.codechef.com/problems/RRATING
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
    int n=0;
    cin>>n;
    multiset<int> ms;
    multiset<int> ms1;
    rep(i,n){
        int t=0;
        cin>>t;
        if(t==1){
            int x=0;
            cin>>x;
            if(ms.sz<2){
                ms.insert(x);
            }
            else{
                if((ms1.sz+ms.sz+1)%3==0){
                    ms.insert(x);
                    ms1.insert(*ms.rbegin());
                    ms.erase(ms.find(*ms.rbegin()));
                }
                else{
                    int tmp = *ms1.begin();
                    if(x>tmp){
                        ms.insert(tmp);
                        ms1.erase(ms1.begin());
                        ms1.insert(x);
                    }
                    else ms.insert(x);
                }
            }
        }
        else{
            if(ms1.sz==0) cout<<"No reviews yet";
            else cout<<*ms1.begin();
            nl
        }
    }
//    print(ms);nl
//    print(ms1);nl
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
