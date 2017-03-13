/* Max Cardinal Bipartite Matching
 * This code uses Augmenting Path algorithm
 * Overall complexity: O(VE)
 * Problem submitted: http://vn.spoj.com/problems/NKBM/
 ***************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 2009;

int n_left, n_right, m, match[N]={};
bool visited[N]={};
vector<int> adj[N];

int augmenting_path(int u){     // return 1 if an augmenting path is found, 0 otherwise
    if(visited[u]) return 0;    // already visited before
    visited[u] = true;
    for(int v : adj[u]){
        if(match[v] == -1 || augmenting_path(match[v])){
            match[v] = u;
            return 1;           // found 1 matching
        }
    }
    return 0;                   // no matching
}

int main(){
    scanf("%d %d %d", &n_left, &n_right, &m);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d %d", &x, &y);
        y += n_left;            // left set: 1 -> n_left | right set: n_left + 1 -> n_left + n_right
        adj[x].push_back(y);    // no need for bi-directional edges
    }

    int ans = 0;
    memset(match, -1, sizeof match);
    for(int i=1; i<=n_left; i++){
        memset(visited, false, sizeof visited);
        ans += augmenting_path(i);
    }

    printf("%d\n", ans);
    return 0;
}
/* Example:
4 5 9
1 1
1 4
2 1
2 2
2 4
3 2
3 3
4 2
4 3
*********/
