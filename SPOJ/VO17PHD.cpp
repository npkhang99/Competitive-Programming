#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> ii;
typedef pair<ii,int> iii;

const int N = 100009;

int n, m;
long long p[N]={}, d[N]={}, f[N]={};
vector<int> a[N], c[N];

iii mp(long long x, long long y, int z){
    return iii(ii(x,y), z);
}

ii dijkstra(){
    priority_queue<iii> q;
    for(int i=1; i<=n; i++)
        d[i] = 1e18;
    q.push(mp(0, p[1], 1)); d[1] = 0; f[1] = p[1];
    while(!q.empty()){
        int u = q.top().second;
        ii du = q.top().first; du.first = -du.first;
        q.pop();
        if(d[u] < du.first || f[u] > du.second) continue;
        if(u == n) return du;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i],
                dv = c[u][i];
            if(d[v] > du.first + dv || (d[v] == du.first + dv && f[v] < du.second + p[v])){
                d[v] = du.first + dv;
                f[v] = du.second + p[v];
                q.push(mp(-d[v], du.second + p[v], v));
            }
        }
    }
    return ii(-1,-1);
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld",&p[i]);
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int x,y,l; scanf("%d%d%d",&x,&y,&l);
        a[x].push_back(y);
        a[y].push_back(x);
        c[x].push_back(l);
        c[y].push_back(l);
    }

    ii ans = dijkstra();
    if(ans.first == -1) printf("impossible\n");
    else printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}
