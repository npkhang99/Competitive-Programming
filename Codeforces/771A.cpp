#include <bits/stdc++.h>
using namespace std;

const int N = 150009;

int n, m, par[N]={}, ranking[N]={};
bool checked[N]={};
long long sz[N]={}, have[N]={};

int root(int p){
    return p == par[p]? p:root(par[p]);
}

void join(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y){
        have[x]++;
        return;
    }

    if(ranking[x] <= ranking[y]){
        if(ranking[x] == ranking[y]) ranking[y]++;
        par[x] = y;
        sz[y] += sz[x];
        have[y] += have[x] + 1;
        return;
    }

    par[y] = x;
    sz[x] += sz[y];
    have[x] += have[y] + 1;
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        par[i] = i;
        sz[i] = 1;
    }

    for(int i=0; i<m; i++){
        int x, y; scanf("%d %d", &x, &y);
        join(x,y);
    }

    bool flag = true;
    for(int i=1; i<=n; i++){
        int u = root(i);
        if(checked[u]) continue;
        if(have[u] != sz[u] * (sz[u]-1) / 2){
            flag = false;
            break;
        }
        checked[u] = true;
    }

    printf("%s\n", flag? "YES":"NO");
    return 0;
}
