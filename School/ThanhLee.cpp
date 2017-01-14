#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N=2009;

int n, m, k, s, t, d[N]={};
vector<iii> a[N];

void dijkstra(){
    int ans = 10E8;
    priority_queue<iii, vector<iii>, greater<iii> > q;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    q.push(iii(0,ii(s,0))); d[s] = 0;
    while(!q.empty()){
        int  u = q.top().second.first,
            du = q.top().first,
            tu = q.top().second.second;
        q.pop();
        if(tu > d[u]) continue;
        if(u == t){ ans = min(ans,tu); continue; }
        for(int i=0; i<a[u].size(); i++){
            int  v = a[u][i].first,
                dv = a[u][i].second.second,
                tv = a[u][i].second.first;
            if(dv + du < k && tu + tv < d[v]){
                d[v] = tv + tu;
                q.push(iii(du+dv, ii(v, tu + tv)));
            }
        }
    }
    printf("%d\n",ans == 10E8? -1:ans);
}

int main(){
    // freopen("ThanhLee.inp","r",stdin);
    // freopen("ThanhLee.out","w",stdout);
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0; i<m; i++){
        int x, y, z, t; scanf("%d%d%d%d",&x,&y,&z,&t);
        a[x].push_back(iii(y,ii(z,t)));
        a[y].push_back(iii(x,ii(z,t)));
    }
    scanf("%d%d",&s,&t);
    dijkstra();
    return 0;
}
