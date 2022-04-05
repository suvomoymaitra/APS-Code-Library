// https://www.codechef.com/problems/ELWINTER
// Concept used : BFS
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
vector<int> visited(100009);
int n,m,z;

void pre(){}

void solve() {
    cin>>n>>m>>z;
    for(int i=0;i<m;i++){
        int a=0,b=0;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int mx = n-1;
    int curr=0;

    queue<int> q1,q2;
//    set<int> tmp;
    map<int,int> m1;

    for(int i=0;i<z;i++){
        int a=0,b=0;
        cin>>a>>b;
        if(a==1){
            visited[b] = 1;
            curr++;
            q1.push(b);
        }
        elif(a==2){
            while(b-- and curr<n){
                while(q1.size()){
                    int tmp = q1.front();
                    q1.pop();
                    for(auto itr:v[tmp]){
                        if(!visited[itr]){
                            visited[itr] = 1;
                            q2.push(itr);
                            curr++;
                        }
                    }
                }
                q1 = q2;
            }
//            if(curr>mx) continue;
//            curr+=b;
//            for(auto itr:tmp) q.push({itr,b});
//            while(q.size()){
//                auto temp = q.front();
//                q.pop();
//                if(temp.second){
//                    for(auto itr:v[temp.first]){
//                        if(visited[itr]) continue;
//                        visited[itr] = 1;
//                        q.push({itr,temp.second-1});
//                        m1[itr] = temp.second-1;
//                    }
//                }
//            }
        }
        else{
            if(visited[b]) cout<<"YES";
            else cout<<"NO";
            nl
        }
    }

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
