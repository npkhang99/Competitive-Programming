#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> lli;

const int N=1000000;

struct Edge{
    int u,v;
    long long val;
}a[4*N];

int n, k=0, parent[N]={}, ranking[N]={};
lli x[N],y[N],z[N];

void doc(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &x[i].first, &y[i].first, &z[i].first);
        x[i].second = y[i].second = z[i].second = i;
    }
}

void makePath(){
    sort(x,x+n); sort(y,y+n); sort(z,z+n);
    for(int i=1; i<n; i++){
        // theo x
        a[k].u=x[i-1].second; a[k].v=x[i].second;
        a[k].val=abs(x[i-1].first-x[i].first); k+=1;
        // theo y
        a[k].u=y[i-1].second; a[k].v=y[i].second;
        a[k].val=abs(y[i-1].first-y[i].first); k+=1;
        // theo z
        a[k].u=z[i-1].second; a[k].v=z[i].second;
        a[k].val=abs(z[i-1].first-z[i].first); k+=1;
    }
}

int root(int p){
    return parent[p]==p? p:root(parent[p]);
}

void join(int p, int q){
    p = root(p);
    q = root(q);
    if(p == q) return;
    if(ranking[p] <= ranking[q]){
        parent[p] = q;
        if(ranking[p] == ranking[q]) ranking[p]++;
    }else parent[q] = p;
}

int comp(Edge a, Edge b){ return a.val<b.val; }

void kruskal(){
    long long ans=0;
    sort(a,a+k,comp);
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=0,cnt=0; i<k; i++)
        if(root(a[i].u) != root(a[i].v)){
            join(a[i].u,a[i].v);
            ans+=a[i].val; cnt+=1;
            if(cnt==n-1) break;
        }
    printf("%lld\n",ans);
}

void xuly(){
    makePath();
    kruskal();
}

int main(){
    doc();
    xuly();
    return 0;
}
