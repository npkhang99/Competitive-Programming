// Kosaraju's algorithm in finding Strongly Connected Component
#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, m, mark[N]={};
vector<int> adj[N], rev[N], S;

void Kosaraju(int u, int pass){ // pass = 1 (original), 2 (transpose)
    mark[u] = 1;

    vector<int> neighbor;
    if(pass == 1) neighbor = adj[u];
    else neighbor = rev[u];
    
    for(int v : neighbor){
        if(mark[v] == -1)
            Kosaraju(v, pass);
    }

    S.push_back(u);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);    // original graph
        rev[y].push_back(x);    // reversed graph (transpose)
    }

    memset(mark, -1, sizeof(mark));

    S.clear(); // first pass is to record the `post-order' of original graph
    for(int i = 1; i <= n; i++){
        if(mark[i] == -1)
            Kosaraju(i, 1);
    }

    memset(mark, -1, sizeof(mark));

    int SCC = 0; // second pass: explore the SCCs based on first pass result
    for(int i = n-1; i >= 0; i--){
        if(mark[S[i]] == -1){
            SCC++;
            Kosaraju(S[i], 2);
        }
    }

    printf("%d\n", SCC);
    return 0;
}
