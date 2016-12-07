// CodeChef
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N=29;

int n, m, T, b[N]={}, x[N]={}, ans = 10E8;
vector<int> a[N];

void reset(){
    ans = 10E8;
    for(int i=0; i<=n; i++){
        a[i].clear();
        b[i] = 0;
        x[i] = i+1;
    }
}

void btrack(int u, int* c, int cnt){
    int fin=1, d[N]={}; b[u] = 1;
    for(int i=1; i<=n; i++) d[i] = c[i];
    d[u] = 1;

    for(int i=0; i<a[u].size(); i++) d[a[u][i]] = 1;
    
    for(int i=1; i<=n; i++)
        if(!d[i]){ fin=0; break; }
    if(fin){ ans = min(ans,cnt); b[u] = 0; return; }
    
    for(int i=1; i<=n; i++)
        btrack(x[i],d,cnt+1);
    b[u] = 0;
}

int comp(int u, int v){
    return a[u].size() > a[u].size();
}

int main(){
    // ios::sync_with_stdio(false);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if(m==0){ printf("%d\n",n); continue; }
        reset();
        for(int i=0; i<m; i++){
            int x,y; scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        sort(x,x+n,comp);
        for(int i=0; i<n; i++) btrack(x[i],b,1);
        printf("%d\n",ans);
    }
    return 0;
}
