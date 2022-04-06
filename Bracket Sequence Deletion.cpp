// https://codeforces.com/contest/1657/problem/C
// Concept used : stack
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define nl cout<<"\n";

bool fun(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
//    cout<<"here";
    return s1==s;
}

void solve() {
    int n=0;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int i = n-1;
    int rem = n;
    int tot = 0;
    int ok=0;
    while(i>=0 and s.size()){
        stack<int> curr;
        int z=0;
        string tmp = "";
        tmp += s[i];
        if(s[i]=='(') curr.push(1);
        else curr.push(0);
        i--;
        int last = s.size();
        z++;
        int xx=0;
        while(i>=0 and s.size() and !curr.empty()){
            z++;
            tmp = move(tmp) + s[i];
//            cout<<i<<" ";
//            cout<<tmp<<" ";
            if(s[i]=='(') curr.push(1);
            else if(!curr.empty() and curr.top()==1) curr.pop();
            else curr.push(0);
            int zz=0;
            if(curr.empty() || (tmp[0]==tmp[tmp.size()-1] and fun(tmp))){
//                cout<<"here";
                rem-=z;
                tot++;
//                cout<<z<<" ";
                while(z--) s.pop_back();
                tmp = "";
                zz=1;
                xx=1;
            }
            if(zz and last==s.size()){
                ok = 1;
                break;
            }
            i--;
            if(tmp=="") break;
//            i--;
        }
        if(ok) break;
    }
    cout<<tot<<" "<<s.size();nl
}

int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
