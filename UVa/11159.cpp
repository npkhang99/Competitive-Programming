#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, m, a[2*N]={}, match[2*N]={}, visited[2*N]={};
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
    int TC; scanf("%d", &TC);
    for(int CASE = 1; CASE <= TC; CASE++){
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for(int i=1; i<=m; i++)
            scanf("%d", &a[n+i]);

        for(int i=1; i<=n+m; i++)
            adj[i].clear();

        for(int i=1; i<=n; i++){
            for(int j=n+1; j<=n+m; j++)
                if((a[i] == 0 && a[j] == 0) || (a[i] != 0 && a[j] % a[i] == 0)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        }

        int ans = 0;
        memset(match, -1, sizeof match);
        for(int i=1; i<=n; i++){
            memset(visited, 0, sizeof visited);
            ans += aug(i);
        }

        printf("Case %d: %d\n", CASE, ans);
    }
    return 0;
}
