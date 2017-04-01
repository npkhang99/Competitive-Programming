#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, m, par[N]={}, ranking[N]={}, set_cnt;
vector<int> enemy[N];
vector<ii> enemy_relation;

int root(int p){
    return p == par[p]? p:root(par[p]);
}

void join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return;
    set_cnt--;
    if(ranking[u] <= ranking[v]){
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }else par[v] = u;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        par[i] = i;
    set_cnt = n;

    for(int j=0; j<m; j++){
        char type; int x, y;
        scanf(" %c %d %d", &type, &x, &y);
        if(type == 'E'){
            enemy[x].push_back(y);
            enemy[y].push_back(x);
            enemy_relation.push_back(ii(x,y));
        }else join(x,y);
    }

    for(ii relation : enemy_relation){
        int x = relation.first,
            y = relation.second;
        for(int z : enemy[y]){
            join(x,z);
        }
        for(int z : enemy[x]){
            join(y,z);
        }
    }

    printf("%d\n", set_cnt);
    return 0;
}
