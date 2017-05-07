#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, m, color[N]={}, b[N]={};
bool in_queue[N]={};
vector<int> adj[N];

void fill(int x, int d, int c){
    queue<int> q;
    q.push(x);
    b[x] = d; color[x] = c; in_queue[x] = true;
    while(!q.empty()){
        int u = q.front(),
            l = b[u];
        q.pop();
        in_queue[u] = false;
        if(b[u] == 0) continue;
        for(int v : adj[u]){
            if(color[v] != c || (color[v] == c && b[v] < l-1)){
                b[v] = l-1;
                color[v] = c;
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
        b[i] = -1;

    int Q; scanf("%d", &Q);
    while(Q--){
        int x, d, c; scanf("%d %d %d", &x, &d, &c);
        fill(x,d,c);
    }

    for(int i=1; i<=n; i++)
        printf("%d\n", color[i]);
    return 0;
}
