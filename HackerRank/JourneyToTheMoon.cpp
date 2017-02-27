// HackerRank - Journey to the Moon
#include <cstdio>
#include <set>
using namespace std;

const int N = 100009;

int n, m, par[N]={}, size[N]={}, ranking[N]={}, setCount=0;
set<int> collection;

int root(int p){ return p == par[p]? p:root(par[p]); }

int join(int u, int v){
    u = root(u); v = root(v);
    if(u == v) return size[u];
    setCount -= 1;
    if(ranking[u] > ranking[v]){
        par[v] = u;
        return size[u] += size[v];
    }else{
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
        return size[v] += size[u];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        par[i] = i;
        size[i] = 1;
        ranking[i] = 0;
    }

    setCount = n;

    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d",&x,&y);
        join(x,y);
    }

    if(setCount == 1){
        printf("0\n");
        return 0;
    }

    for(int i=0; i<n; i++)
        collection.insert(root(i));

    long long ans = 0, last = size[*collection.begin()];
    for(set<int>::iterator it=++collection.begin(); it != collection.end(); it++){
        // fprintf(stderr, "%d\n", *it);
        ans += last * size[*it];
        last += size[*it];
    }
    printf("%lld\n",ans);
    return 0;
}
