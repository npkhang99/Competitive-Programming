// Dijkstra's algorithm - Finding Single-Source Shortest Path from S to T using priority queue
// Time complexity: O((V+E) log V)
// NOTE: This Dijkstra's variant can cause duplicate items in the priority queue
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;
const int INF = (int)1e9;

int n, m, s, t, dist[N]={};
vector<ii> a[N];            // AdjList: (outgoing edge, cost)

void doc(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0; i<m; i++){
        int x,y,val; scanf("%d%d%d",&x,&y,&val);
        a[x].push_back(ii(y,val));
        a[y].push_back(ii(x,val));
    }
}

void dijkstra(int s, int t){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[s] = 0;

    pq.push(ii(0,s));                               // starting from s with 0 initial cost
    while(!pq.empty()){                             // main loop
        ii front = pq.top(); pq.pop();              // greedy move
        int u = front.second, d = front.first;
        if(d > dist[u]) continue;                   // important!!!
        for(int i=0; i<a[u].size(); i++){           // all outgoing edges from u
            int v = a[u][i].first, cost = a[u][i].second;
            if(d + cost < dist[v]){
                dist[v] = d + cost;                  // relax operation
                pq.push(ii(dist[v],v));
            }
        }
    }

    if(dist[t] != INF) printf("%d\n",dist[t]);
    else printf("-1\n");
}

int main(){
    doc();
    dijkstra(s,t);
    return 0;
}
