// https://www.codechef.com/problems/TRAVELLING
// Concept used : Dijkstra's Shortest path algorithm and Disjoint Set Union
#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define INF 1e9
vector<vector<pair<int,int>>> adj;
int arr[200009];


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
    if(aa!=bb)
        arr[bb] = aa;
}

void dijkstra(int source,vector<int> &d,vector<int> &p){
    int n = adj.size();
//    p.assign(n,-1);
    d.assign(n+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,source});
    d[source] = 0;
    while(q.size()){
        pair<int,int> tmp = q.top();
        q.pop();
        int v = tmp.second;
        int v_d = tmp.first;
        if(v_d!=d[v]) continue;
        for(auto edges:adj[v]){
            int to = edges.first;
            int weight = edges.second;
            if(d[v]+weight<d[to]){
                d[to] = d[v]+weight;
//                p[to] = v;
                q.push({d[to],to});
            }
        }
    }
//     for(int i=1;i<=n;i++) cout<<d[i]<<" ";
//     cout<<"\n";
}

void suvo(){
    int n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n+2;i++) arr[i] = i;
    // vector<pair<int,int>> adj[n+1];
    adj.clear();
    vector<pair<int,int>> tmp;
    adj.assign(n+3,tmp);
    vector<int> curr(n+1,0);
    for(int i=0;i<m;i++){
        int a=0,b=0;
        cin>>a>>b;
        adj[a].push_back({b,0ll});
            adj[b].push_back({a,0ll});
        if(llabs(a-b)==1){
            curr[min(a,b)] = 1;
        }
        dsuunion(a,b);
    }
    if(dsuroot(1)==dsuroot(n)){
        cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=n-1;i++){
        if(curr[i]==0 and dsuroot(i)!=dsuroot(i+1)){
            adj[i].push_back({i+1,1ll});
            adj[i+1].push_back({i,1ll});
        }
//        if(curr[i]==0){
//            adj[i].push_back({i+1,1ll});
//            adj[i+1].push_back({i,1ll});
//        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<adj[i].size();j++) cout<<adj[i][j].first<<" "<<adj[i][j].second<<":";
    //     cout<<"\n";
    // }
    vector<int> d,p;
    dijkstra(1,d,p);
//    for(int i=1;i<=n;i++) cout<<d[n]<<" ";
//    cout<<"\n";
    cout<<d[n]<<"\n";
}

int32_t main() {
    // your code goes here
    int t=0;
    cin>>t;
    while(t--)
        suvo();
    return 0;
}
