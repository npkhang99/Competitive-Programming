/* Shortest Path Faster Algorithm - Finding Single-Source Shortest Path from S to T that utilizes a queue to eliminate redundant operations in Bellman-Ford algorithm
 * Time complexity: O(kE) - k is a number depending on the graph. Maximum k can be V (the same as Bellman-Ford)
 * Requirements:
 *  - A graph stored in an Adjacency List (adj)
 *  - A distance array to record the distance from source to every vertex (dist)
 *  - A queue to stores the vertex to be processed (q)
 *  - An array to denote if a vertex is in the queue or not (in_queue)
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;
const int INF = (int)1e9;

int n, m, s, t, dist[N]={};
bool in_queue[N]={};
vector<ii> adj[N];            // Adjacency List: ii(outgoing edge, cost)

void doc(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0; i<m; i++){
        int x,y,val; scanf("%d%d%d",&x,&y,&val);
        adj[x].push_back(ii(y,val));
        adj[y].push_back(ii(x,val));
    }
}

void spfa(int s, int t){
    queue<int> q;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
        is_queue[i] = false;
    }

    q.push(s);
    d[s] = 0;
    in_queue[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        in_queue[u] = false;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first,
                cost = adj[u][i].second;
            if(d[u] + cost < d[v]){
                d[v] = d[u] + cost;
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    if(dist[t] != INF) printf("%d\n",dist[t]);
    else printf("impossible\n");
}

int main(){
    doc();
    spfa(s,t);
    return 0;
}

