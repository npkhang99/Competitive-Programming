#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define MOD 1000000007

typedef pair<int,int> ii;

const int N=1509;

int n, m, tr[N]={}, d[N]={}, b[N]={};
vector<ii> a[N], edgeList;
map<ii,int> ans;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    for(int i=1; i<=n; i++) d[i] = 10E8, b[i] = 0, tr[i] = i;
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second, du = q.top().first; q.pop();
        if(b[u]) continue; b[u] = 1;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if(d[v] > du + dv)
                d[v] = du+dv, tr[v] = u, q.push(ii(d[v],v));
        }
    }
}

void trace(int i){
    if(i==tr[i]) return;
    int j = tr[i];
    ans[ii(j,i)] = (ans[ii(j,i)] + 1) % MOD;
    trace(j);
}

int main(){
    // freopen("Paths.inp","r",stdin);
    // freopen("Paths.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int x,y,v; scanf("%d%d%d",&x,&y,&v);
        a[x].push_back(ii(y,v));
        edgeList.push_back(ii(x,y));
    }

    for(int i=1; i<=n; i++){
        dijkstra(i);
        for(int j=1; j<=n; j++)
            if(i!=j) trace(j);
    }

    for(int i=0; i<edgeList.size(); i++)
        printf("%d\n",ans[ii(edgeList[i].first,edgeList[i].second)]);
    return 0;
}
