#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int N=109;

int n, m, e, t, T, b[N]={};
vector<ii> a[N];

void dijkstra(){
    int cnt = 0;
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0,e));
    while(!q.empty()){
        int u = q.top().second, du = q.top().first; q.pop();
        if(du > t) continue;
        if(du <= t) b[u] = 1;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if(du + dv <= t) q.push(ii(du+dv,v));
        }
    }
    for(int i=1; i<=n; i++) if(b[i]) cnt+=1;
    printf("%d\n",cnt);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&e,&t,&m);
        for(int i=0; i<=n; i++) a[i].clear(), b[i] = 0;
        for(int i=0; i<m; i++){
            int x,y,v; scanf("%d%d%d",&x,&y,&v);
            a[y].push_back(ii(x,v));
        }
        dijkstra();
        if(T) printf("\n");
    }
    return 0;
}
