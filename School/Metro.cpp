// VOI17 - Task 4 - 1st task of Day 2
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;

const int N = 100009;

int n, m, s, t;
ll phi, d[N]={};
vector<iii> a[N];

iii mp(ll x, ll y, int z){
    return iii(ii(x,y), z);
}

ll f(ll i, ll j){
    return i * phi + j;
}

ll dijkstra(){
    priority_queue<iii> q;
    for(int i=1; i<=n; i++)
        d[i] = 1e18;
    d[s] = 0;
    for(int i=0; i<a[s].size(); i++){
        iii v = a[s][i];
        q.push(mp(-v.fi.fi, -v.fi.se, v.se));
        d[v.se] = v.fi.fi;
    }

    while(!q.empty()){
        int u = q.top().se;
        ll du = -q.top().fi.fi, id_last = -q.top().fi.se;
        q.pop();
        if(du > d[u]) continue;
        if(u == t) return du;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].se;
            ll dv = a[u][i].fi.fi, id_next = a[u][i].fi.se;
            if(d[v] > du + dv + f(id_last, id_next)){
                d[v] = du + dv + f(id_last, id_next);
                q.push(mp(-d[v], -id_next, v));
            }
        }
    }
    return -1;
}

int main(){
    freopen("Metro.inp","r",stdin);
    freopen("Metro.out","w",stdout);
    scanf("%d %d %d %d %lld", &n, &m, &s, &t, &phi);
    for(int i=0; i<m; i++){
        int x, y;
        ll val;
        scanf("%d %d %lld",&x,&y,&val);
        a[x].push_back(mp(val,i+1,y));
    }

    printf("%lld\n", dijkstra());
    return 0;
}
