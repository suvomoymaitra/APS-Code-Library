// https://www.codechef.com/ALPAST01/problems/SMCMP
// Concept used : Disjoint Set Union
#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define INF 1e9
#define nl cout<<"\n";

int arr[100009];

int dsuroot(int a){
    while(a!=arr[a]){
        arr[a] = arr[arr[a]];
        a = arr[a];
    }
    return a;
}

void dsuunion(int a,int b){
    int aa = dsuroot(a);
    int bb = dsuroot(b);
    if(aa!=bb) arr[bb] = aa;
}

void suvo(){
    int n=0,q=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++) arr[i] = i;
    while(q--){
        int a=0,b=0,c=0;
        cin>>a>>b>>c;
        if(a==1) dsuunion(c,b);
        else{
            if(dsuroot(c)==dsuroot(b)) cout<<"Yes";
            else cout<<"No";
            nl
        }
    }
}

int32_t main() {
    // your code goes here
    int t=1;
//    cin>>t;
    while(t--)
        suvo();
    return 0;
}
