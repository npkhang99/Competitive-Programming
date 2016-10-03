#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define all(seq) seq.begin(),seq.end()
#define fi first
#define se second

typedef pair<int,int> ii;

const int N=100009;

int n, m, k, d[N]={};
vector<int> a[N], choose;

void BFS(){
    queue<ii> q;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    for(int i=0; i<choose.size(); i++)
        q.push(ii(choose[i],choose[i])), d[choose[i]] = 0;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        printf("%d %d\n",u.fi,u.se);
        for(int i=0; i<a[u.fi].size(); i++){
            ii v(a[u.fi][i],u.se);
            if(v.se != u.se){
                printf("%d\n",d[u.fi]+d[v.fi]+1);
                return;
            }else if(d[u.fi]+1 < d[v.fi])
                q.push(v), d[v.fi] = d[u.fi]+1;
        }
    }
}

int main(){
    // freopen("ReInvent.inp","r",stdin);
    // freopen("ReInvent.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0; i<k; i++){
        int x; scanf("%d",&x);
        choose.push_back(x);
    }
    BFS();
    return 0;
}
