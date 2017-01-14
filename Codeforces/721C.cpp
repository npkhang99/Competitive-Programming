#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N=5009;

int n, m, T, dp[N][N]={}, L[N]={}, tr[N][N]={};
vector<ii> a[N];

void BFS(){
    queue<ii> q;
    q.push(ii(1,0));
    dp[1][0] = 0; L[1] = 0;
    while(!q.empty()){
        int u = q.front().first, du = q.front().second; q.pop();
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if()
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0; i<m; i++){
        int x,y,v; scanf("%d%d%d",&x,&y,&v);
        a[x].push_back(ii(y,v));
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) dp[i][j] = 10E8+9;
    BFS();
    return 0;
}
