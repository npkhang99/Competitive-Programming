#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 5009;
const int INF = 0x3f3f3f3f;

int n, m, T, memo[N][N]={};
vector<ii> a[N];

// minimum time required to arrive at vertex v if we visit j vertices (including 1 and v)
int dp(int v, int j){
    if(j < 1) return INF;
    if(memo[v][j] != -1) return memo[v][j];

    memo[v][j] = INF;
    for(int i=0; i < a[v].size(); i++){
        int u = a[v][i].first,
            w = a[v][i].second;
        memo[v][j] = min(memo[v][j], dp(u, j-1) + w);
    }
    return memo[v][j];
}

void trace(int v, int j){
    if(v == 1){
        printf("1");
        return;
    }
    for(int i=0; i<a[v].size(); i++){
        int u = a[v][i].first,
            w = a[v][i].second;
        if(memo[v][j] == memo[u][j-1] + w){
            trace(u,j-1);
            printf(" %d", v);
            return;
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0; i<m; i++){
        int x,y,v; scanf("%d%d%d",&x,&y,&v);
        a[y].push_back(ii(x,v));
    }

    memset(memo, -1, sizeof memo);
    memo[1][1] = 0;
    int ans = 0;
    for(int i=2; i<=n; i++)
        if(dp(n,i) <= T) ans = i;

    printf("%d\n", ans);
    trace(n, ans);
    printf("\n");
    return 0;
}
