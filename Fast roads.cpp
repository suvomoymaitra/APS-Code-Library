// https://www.codechef.com/ALPAST01/problems/FASTROAD
// Concept used : Dijkstra's shortest path algorithm
#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define INF 1e13
#define nl cout<<"\n";


void suvo(){
    int n=0,m=0,s=0,des=0;
    cin>>n>>m>>s>>des;
    vector<vector<pair<int,double>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a=0,b=0;
        double c=0,d=0;
        cin>>a>>b>>c>>d;
        double time = c/d;
//        cout<<time;nl
        adj[a].push_back({b,time});
        adj[b].push_back({a,time});
    }
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
    vector<double> dist(n+1,INF);
    dist[s] = 0;
    q.push({0,s});
    while(q.size()){
        pair<double,int> tmp = q.top();
        q.pop();
        double v_d = tmp.first;
        int v = tmp.second;
        for(auto itr:adj[v]){
            int to = itr.first;
            double weight = itr.second;
            if(dist[v]+weight<dist[to]){
                dist[to] = dist[v]+weight;
                q.push({dist[to],to});
            }
        }
    }
//    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
//    nl
    if(dist[des]==INF) cout<<-1;
    else{
//        cout<<dist[des];
        cout << fixed << setprecision(4) <<dist[des];
    }
    nl

}

int32_t main() {
    // your code goes here
    int t=1;
    cin>>t;
    while(t--)
        suvo();
    return 0;
}
