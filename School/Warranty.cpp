#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int N=1009;

int n, m, s1, s2, k, d[N]={};
vector<ii> a[N];

void dijkstra(int s){
    bool b[N]={};
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second, du = q.top().first; q.pop();
        if(du > d[u]) continue;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if(d[u] + dv < d[v]) d[v] = du + dv, q.push(ii(d[v],v));
        }
    }
}

int main(){
    freopen("Warranty.inp","r",stdin);
    freopen("Warranty.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&m,&s1,&s2,&k);
    for(int i=0; i<m; i++){
        int x,y,v; scanf("%d%d%d",&x,&y,&v);
        a[x].push_back(ii(y,v));
        a[y].push_back(ii(x,v));
    }

    for(int i=1; i<=n; i++) d[i] = 10E8;
    dijkstra(s1); dijkstra(s2);
    int flag = 1;
    for(int i=1; i<=n; i++)
        if(d[i] > k){
            printf("%d ",i);
            flag = 0;
        }
    if(flag) printf("-1\n");
    else printf("\n");
    return 0;
}
