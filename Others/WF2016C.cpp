#include <bits/stdc++.h>
using namespace std;

const int N = 59;

int n, k, a[N][N]={}, b[N][N]={}, par[N]={};

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

bool the_same(int u, int v){
    for(int i=0; i<k; i++){
        bool found = false;
        for(int j=0; j<k; j++)
            if(b[u][i] == b[v][j]) found = true;
        if(!found) return false;
    }
    return true;
}

int find(int i, int p){
    for(int j=0; j<k; j++)
        if(!b[i][j]) return -1;
        else if(b[i][j] == p) return j;
}

int main(){
    while(~scanf("%d %d", &n, &k)){
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++)
                scanf("%d", &a[i][j]);

        memset(b, 0, sizeof b);
        for(int i=0; i<n; i++)
            par[i] = i;

        for(int i=0; i<n; i++){
            b[i][0] = 1;
            for(int j=1; j<k; j++){
                int p = 1,
                    e = find(i, p);
                while(~e){
                    if(a[i][j] < a[i][e]) p = p*2;
                    else p = p*2 + 1;
                    e = find(i, p);
                }
                b[i][j] = p;
            }
        }

        int cnt = n;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(the_same(i,j)) cnt -= join(i,j);

        printf("%d\n", cnt);
    }
    return 0;
}
