// https://www.codechef.com/ALPAST01/problems/VERYHARD
// Concept used : Segment tree
#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define INF 1e13
#define nl cout<<"\n";

int arr[500009];
int tree[2000036][5];
int k;

// tmp be the tree number to be used or the desired remainder

void build(int curr,int tl,int tr,int tmp){
    if(tl==tr){
        tree[curr][tmp] = 0;
    }
    else{
        int mid = (tl+tr)/2;
        build(2*curr,tl,mid,tmp);
        build(2*curr+1,mid+1,tr,tmp);
        tree[curr][tmp] = tree[2*curr][tmp] + tree[2*curr+1][tmp];
    }
}

void update(int curr,int ind,int val,int tl,int tr,int tmp){
    if(tl==tr){
//        tree[curr][tmp] += val;
        tree[curr][tmp] = val;
//        tree[curr][tmp] = (tree[curr][tmp]==tmp);
    }
    else{
        int mid = (tl+tr)/2;
        if(ind<=mid) update(2*curr,ind,val,tl,mid,tmp);
        else update(2*curr+1,ind,val,mid+1,tr,tmp);
        tree[curr][tmp] = tree[2*curr][tmp]+tree[2*curr+1][tmp];
    }
}

int query(int curr,int l,int r,int tl,int tr,int tmp){
//    if(tmp==3) cout<<"here";nl
    if(l>r) return 0;
//    if(l==r) (tree[curr][tmp]==tmp);
    if(l==tl and r==tr) return tree[curr][tmp];
    int mid = (tl+tr)/2;
    int ans1 = query(2*curr,l,min(r,mid),tl,mid,tmp);
    int ans2 = query(2*curr+1,max(mid+1,l),r,mid+1,tr,tmp);
    return ans1+ans2;
}



void suvo(){
    int n=0,q=0;
    cin>>n>>q>>k;
    for(int i=0;i<5;i++) build(1,1,n,i);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
//        for(int j=0;j<5;j++){
            update(1,i,1,1,n,arr[i]%k);
//        }
    }
    while(q--){
        int ch=0;
        cin>>ch;
        if(ch==1){
            int p=0,v=0;
            cin>>p>>v;
//            for(int j=0;j<5;j++)
            update(1,p,0,1,n,arr[p]%k);
            arr[p] += v;
            update(1,p,1,1,n,arr[p]%k);
        }
        else{
            int l=0,r=0,rem=0;
            cin>>l>>r>>rem;
            cout<<query(1,l,r,1,n,rem);
            nl
//            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";nl
//            for(int i=1;i<=4*n;i++) cout<<tree[i][3]<<" ";
//            nl
        }
//        cout<<"here";
    }
}

int32_t main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
//    cin>>t;
    while(t--)
        suvo();
    return 0;
}
