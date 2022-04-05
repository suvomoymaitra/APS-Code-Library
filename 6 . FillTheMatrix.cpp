// https://www.codechef.com/problems/FILLMTR
// Concept used : Disjoint Set union
#include<bits/stdc++.h>
#define int long long int
#define nl cout<<"\n";
using namespace std;
vector<int> par(100009),dsuarr(100009);

int dsufind(int a){
    if(a==dsuarr[a]) return a;
    int tmp = dsuarr[a];
    dsuarr[a] = dsufind(tmp);
    par[a] = par[a]^par[tmp];
    return dsuarr[a];
}

bool dsuunion(int a,int b,int val){
    int tmpa = dsufind(a);
    int tmpb = dsufind(b);
    if(tmpa==tmpb){
        if(val!=(par[a]^par[b])) return false;
        else return true;
    }
    dsuarr[tmpa] = tmpb;
    par[tmpa] = par[a]^par[b]^val;
    return true;
}

int32_t main(){
    int test = 0;
    cin>>test;
    while(test--){
        int n=0,q=0;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            dsuarr[i] = i;
            par[i] = 0;
        }
        bool ans = true;
        while(q--){
            int a=0,b=0,c=0;
            cin>>a>>b>>c;
            a--,b--;
            if(!dsuunion(a,b,c)) ans = false;
            if(a==b and c==1) ans = false;
        }
        if(ans) cout<<"yes";
        else cout<<"no";
        nl
    }
    return 0;
}
