#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int N = 20009;

int n, m, s, t, T, d[N]={};
vector<ii> a[N];

int dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second, du = q.top().first; q.pop();
        if(u==t) return du;
        if(du > d[u]) continue;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if(d[v] > dv + du) d[v] = dv+du, q.push(ii(d[v],v));
        }
    }
    return 10E8;
}

int main(){
    scanf("%d",&T);
    for(int _ = 0; _ < T;){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i=0; i<n; i++) a[i].clear(), d[i] = 10E8;
        for(int i=0; i<m; i++){
            int x, y, val; scanf("%d%d%d",&x,&y,&val);
            a[x].push_back(ii(y,val));
            a[y].push_back(ii(x,val));
        }
        int ans = dijkstra();
        if(ans==10E8) printf("Case #%d: unreachable\n", ++_);
        else printf("Case #%d: %d\n", ++_, ans);
    }
    return 0;
}
