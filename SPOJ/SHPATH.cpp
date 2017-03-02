#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 10009;

int n, m;
long long d[N]={};
vector<ii> adj[N]={};
unordered_map<string,int> mapper;

long long dijkstra(int s, int t){
    priority_queue<ii> q;
    memset(d, 0x3f, sizeof d);
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second,
            du = -q.top().first;
        q.pop();
        if(u == t) return du;
        if(du > d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first,
                dv = adj[u][i].second;
            if(du + dv < d[v]){
                d[v] = du + dv;
                q.push(ii(-d[v],v));
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int TC; cin>> TC;
    while(TC--){
        cin>> n;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            string st; cin>> st;
            mapper[st] = i;
            cin>> m;
            while(m--){
                int u, v; cin>> u>> v;
                adj[i].push_back(ii(u,v));
            }
        }

        cin>> m;
        while(m--){
            string u, v;
            cin>> u>> v;
            cout<< dijkstra(mapper[u], mapper[v])<< '\n';
        }
    }
    return 0;
}
