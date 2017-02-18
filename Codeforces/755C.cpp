#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, par[N]={};

int root(int p){
    return p == par[p]? p:root(par[p]);
}

int join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return 0;
    par[u] = v;
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        par[i] = i;

    int ans = n;
    for(int i=1; i<=n; i++){
        int p; scanf("%d",&p);
        ans -= join(i,p);
    }

    printf("%d\n",ans);
    return 0;
}
