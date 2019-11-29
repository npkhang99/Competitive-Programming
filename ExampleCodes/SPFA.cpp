/* Shortest Path Faster Algorithm - Finding Single-Source Shortest Path from S to T that utilizes a queue to eliminate
    redundant operations in Bellman-Ford algorithm
 * Time complexity: O(kE) - k is a number depending on the graph. Maximum k can be V (the same as Bellman-Ford)
 * Requirements:
 *  - A graph stored in an Adjacency List (adj)
 *  - A distance array to record the distance from source to every vertex (dist)
 *  - A queue to stores the vertex to be processed (q)
 *  - An array to denote if a vertex is in the queue or not (in_queue)
 * Tested with:
 *  - Codeforces 20C. Dijkstra? (https://codeforces.com/problemset/problem/20/C) - TLE
 *  - SPOJ TRVCOST. Travelling cost (https://www.spoj.com/problems/TRVCOST/) - AC
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;
const int INF = (int) 1e9;

int n, m, s, t, dist[N] = {};
bool in_queue[N] = {};
vector<ii> adj[N];

void spfa(int s, int t){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        in_queue[i] = false;
    }

    q.push(s);
    dist[s] = 0;
    in_queue[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first,
                cost = adj[u][i].second;
            if (dist[u] + cost < dist[v]){
                dist[v] = dist[u] + cost;
                if (!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    for (int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    spfa(s, t);

    if (dist[t] != INF) {
        cout << dist[t] << "\n";
    }
    else {
        cout << "impossible\n";
    }
    return 0;
}
