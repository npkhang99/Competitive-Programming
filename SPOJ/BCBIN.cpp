// http://www.spoj.com/PTIT/problems/BCBIN/
#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, par[N]={}, setRank[N]={};

int root(int p){
    return p == par[p]? p:root(par[p]);
}

void join(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if (setRank[x] > setRank[y]) par[y] = x;
    else{
        par[x] = y;
        if (setRank[x] == setRank[y]) setRank[y]++;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=10000; i++)
        par[i] = i;

    for(int i=0; i<n; i++){
        int x, y, type; scanf("%d%d%d", &x, &y, &type);
        if(type == 1) join(x,y);
        else printf("%d\n", root(x) == root(y));
    }
    return 0;
}
