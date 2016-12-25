#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int,int> ii;
typedef pair<ll,ii> iii;

const int N = 100009;

int n, m, par[N]={}, ranking[N]={};
ll c, setCount;
iii a[N]={};

int root(int p){ return p == par[p]? p:root(par[p]); }

bool join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return false;
    setCount -= 1;
    if(ranking[u] <= ranking[v]){
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }else par[v] = u;
    return true;
}

int main(){
    int TC; scanf("%d",&TC);
    for(int T=1; T<=TC; T++){
        scanf("%d%d%lld", &n, &m, &c);
        for(int i=1; i<=n; i++)
            par[i] = i, ranking[i] = 0;
        setCount = n;
        for(int i=0; i<m; i++)
            scanf("%d%d%lld", &a[i].second.first, &a[i].second.second, &a[i].first);

        sort(a,a+m);
        ll ans = 0;
        for(int i=0; i<m; i++){
            if(a[i].first >= c) break;
            if(join(a[i].second.first, a[i].second.second)) ans += a[i].first;
        }
        printf("Case #%d: %lld %lld\n", T, ans + setCount*c, setCount);
    }
    return 0;
}
