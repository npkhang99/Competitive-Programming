// SPOJ submission 18833287 (CPP14) plaintext list. Status: AC, problem V8ORG, contest SPOJVN. By mansblacks (Khang), 2017-02-24 04:59:39.
#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, limit, par[N]={}, current_height=0, descendant[N]={};
bool eliminated[N]={};
vector<int> child[N], at[N];

void dfs(int u, int h){
    at[h].push_back(u);
    current_height = max(current_height, h);
    for(int v : child[u])
        dfs(v, h+1);
}

int main(){
    scanf("%d%d", &limit, &n);
    par[1] = 1;
    for(int i=2; i<=n; i++){
        scanf("%d", &par[i]);
        child[par[i]].push_back(i);
    }

    dfs(1,1);

    for(int i=1; i<=n; i++)
        descendant[i] = 1;

    int ans = 0;
    while(current_height){
        for(int i : at[current_height]){
            if(descendant[i] >= limit){
                eliminated[i] = true; ans++;
                continue;
            }
            descendant[par[i]] += descendant[i];
        }
        current_height--;
    }

    printf("%d\n", ans);
    return 0;
}
