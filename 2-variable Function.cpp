// https://atcoder.jp/contests/abc246/tasks/abc246_d
// Concept used : Binary search over the answer
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl cout<<"\n";

void solve() {
    int n=0;
    cin>>n;
    int ans = LLONG_MAX;
    for(int i=0;i<=1000000;i++) {
        int l=i,r=1000000;
        while(l<r){
            int mid = (l+r)/2;
            int val = (i*i*i) + (i*i*mid) + (i*mid*mid) + (mid*mid*mid);
            if(val<n) l = mid+1;
            else{
                r = mid;
            }
        }
        ans = min(ans,i*i*i + i*i*l + i*l*l + l*l*l);
    }
    cout<<ans;
}

int32_t main(){
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
