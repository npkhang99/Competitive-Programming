// HackerRank - World CodeSprint 8 - Roads and Libraries
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, m;
long long road, lib;
bool b[N]={};
vector<int> a[N];

void init(){
    for(int i=1; i<=n; i++){
        a[i].clear();
        b[i] = false;
    }
}

long long bfs(int s){
    queue<int> q; q.push(s);
    int cnt = 0; b[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cnt += 1;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i];
            if(!b[v]) q.push(v), b[v] = true;
        }
    }
    return cnt;
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        init();
        scanf("%d%d%lld%lld", &n, &m, &lib, &road);
        for(int i=0; i<m; i++){
            int x, y; scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }

        if(lib <= road){
            printf("%lld\n", (long long)n * lib);
            continue;
        }

        long long ans = 0;
        for(int i=1; i<=n; i++)
            if(!b[i])
                ans += lib + road * (bfs(i) - 1ll);

        printf("%lld\n", ans);
    }
    return 0;
}
