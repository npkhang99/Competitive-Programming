#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

const int N=100009;

int n, m, d[N]={};
vector<int> a[N];

void BFS(){
    queue<int> q;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    q.push(1); d[1] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i];
            if(d[u]+1 < d[v])
                d[v] = d[u]+1, q.push(v);
        }
    }
}

int main(){
    // freopen("BFS1.inp","r",stdin);
    // freopen("BFS1.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    BFS();
    for(int i=1; i<=n; i++)
        printf("%d\n",d[i]==int(10E8)? -1:d[i]);
    return 0;
}
