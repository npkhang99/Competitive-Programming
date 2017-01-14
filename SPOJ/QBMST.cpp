// SPOJ submission 17415876 (C++ 5) plaintext list. Status: AC, problem QBMST, contest SPOJVN. By mansblacks (Khang), 2016-08-02 06:21:07.
#include <stdio.h>         // scanf printf
#include <algorithm>       // sort
using namespace std;

const int N=100009;

struct Edge{
    int u,v,val;
}a[N];

int n, m, root[N]={};

int findRoot(int p){
    if(root[p]==p) return p;
    else return root[p] = findRoot(root[p]);
}

void join(int p, int q){
    root[findRoot(p)] = findRoot(q);
}

int comp(Edge a, Edge b){
    return a.val<b.val;
}

int kruskal(){
    int ans = 0;
    for(int i=0; i<n; i++) root[i] = i;
    for(int i=0; i<m; i++)
        if(findRoot(a[i].u) != findRoot(a[i].v)){
            join(a[i].u,a[i].v);
            ans+=a[i].val;
        }
    return ans;
}

int main(){
    scanf("%d%d\n",&n,&m);
    for(int i=0; i<m; i++){
        int x,y,z; scanf("%d%d%d\n",&x,&y,&z);
        a[i].u = x-1; a[i].v = y-1; a[i].val = z;
    }
    sort(a,a+m,comp);
    printf("%d\n",kruskal());
    return 0;
}
