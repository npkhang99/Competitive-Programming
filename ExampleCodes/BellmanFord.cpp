/* Bellman-Ford algorithm - SSSP on Graph with Negative Weight Cycle
 * Time complexity: O(VE)
 * Examples:
 * - Graph has negative weight, but no negative cycle
    5 5 1
    1 2 1
    1 3 10
    2 4 2
    3 4 -10
    4 5 3
 * - Graph has negative cycle
    3 3 1
    1 2 1000
    2 3 15
    3 2 -42
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1000000000;

int V, E, s, dist[1009];
vector<ii> adj[1009];

int main(){
    scanf("%d %d %d", &V, &E, &s);
    for(int i = 0; i < E; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(ii(v,w)); // directed graph
    }

    for(int i = 1; i <= V; i++)
        dist[i] = INF;
    dist[s] = 0;

    for(int i=1; i<=V-1; i++){                     // relax all E edges V-1 times
        for(int u = 1; u <= V; u++)                        // next 2 loops = O(V)
            for(int j = 0; j < adj[u].size(); j++){
                int v = adj[u][j].first,
                    w = adj[u][j].second;
                if(dist[u] + w < dist[v]) dist[v] = dist[u] + w;         // relax
            }
    }

    bool has_negative_cycle = false;
    for(int u = 1; u <= V; u++)      // one more pass to check for negative cycle
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first,
                w = adj[u][j].second;
            if(dist[u] + w < dist[v])                     // this should be false
                has_negative_cycle = true;       // if not, negative cycle exists
        }

    if(has_negative_cycle) printf("Has negative cycle!\n");
    else printf("No negative cycle!\n");

    if(!has_negative_cycle)
        for(int i = 1; i <= V; i++)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    return 0;
}
