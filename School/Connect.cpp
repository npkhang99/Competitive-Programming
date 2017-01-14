#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=100009;

int n, m, Q, par[N]={}, x, y;

ii root(int p, int cnt=1){
    return p == par[p]? ii(p,cnt):root(par[p],cnt+1);
}

void join(int p, int q){
    ii root_p = root(p), root_q = root(q);
    if(root_p.second > root_q.second) swap(root_p,root_q);
    par[root_p.first] = root_q.first;
}

int main(){
    // freopen("Connect.inp","r",stdin);
    // freopen("Connect.out","w",stdout);
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1; i<=n; i++) par[i] = i;
    for(int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        join(x,y);
    }
    for(int i=0; i<Q; i++){
        scanf("%d%d",&x,&y);
        printf("%s\n",root(x).first == root(y).first? "YES":"NO");
    }
    return 0;
}
