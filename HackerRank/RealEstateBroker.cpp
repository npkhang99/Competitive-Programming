// HackerRank - Women's CodeSprint 2 - Real Estate Broker
#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

struct House{
    int area, price;
}house[N];

struct Client{
    int area, price;
}client[N];

int n, m, match[2*N]={}, visited[2*N]={};
vector<int> adj[2*N];

int aug(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    for(int v : adj[u]){
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &client[i].area, &client[i].price);
    for(int i=1; i<=m; i++)
        scanf("%d %d", &house[i].area, &house[i].price);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(client[i].area <= house[j].area && client[i].price >= house[j].price){
                adj[i].push_back(n+j);
                adj[n+j].push_back(i);
            }

    int ans = 0;
    memset(match, -1, sizeof match);
    for(int i=1; i<=n; i++){
        memset(visited, 0, sizeof visited);
        ans += aug(i);
    }

    printf("%d\n", ans);
    return 0;
}
